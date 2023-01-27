//
// Created by 徐朝阳 on 2022/7/4.
//

# include <iomanip>
# include <vector>        //提供向量头文件
# include <algorithm>     // 算法头文件，提供迭代器
# include <cmath>
# include <cstddef>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <fstream>           //文件流库函数
# include <ctime>
# include "mpi.h"
#define TRUE 1
#define FALSE 0
#define bool int

#define MAX_N 100  //允许的最大未知数个数
#define MAX_A MAX_N * MAX_N //允许最大系数的个数

#define MAX_ITERATION 10000 //最大迭代次数
#define TOLERANCE 0.0001

int pID, pSize ; //pID:当前进程ID, pSize:总进程数
int n, iteration = 0; //n:未知数的个数，iteration：迭代的次数
float x[MAX_N], new_x[MAX_N], result_x[MAX_N];
float a[MAX_N][MAX_N]; //系数
float b[MAX_N];

void input(){
    srand(time(0));
    double sum = 0;
    for (int i = 0; i < MAX_N; i++) {
        sum=0;
        for (int j = 0; j < MAX_N; j++) {
            if (j==i)
                continue;
            a[i][j]=rand() %10 - 5;
            sum+= abs(a[i][j]);
        }
        if (rand() & 1)//严格对角占优
            a[i][i]=sum+1;
        else
            a[i][i]=-sum-1;

    }
    for (int i = 0; i < n; i++) {
       b[i]=rand() % 10 - 5;
       x[i]=0;
    }
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            printf("a=%f",a[i][j]);
        }
        printf("\n");
    }
//    int i, j;
//
//    printf("The n is %d\n", n);
//    fflush(stdout);
//    //输入系数
//    for(i = 0; i < n; i++){
//        //printf("Input a[%d][0] to a[%d][n-1]:\n", i, i);
//        //fflush(stdout);
//        for(j = 0; j < n; j++)
//            scanf("%f", &a[i][j]);
//    }
//    //printf("Input b[0] to b[n-1]:\n");
//    //fflush(stdout);
//    for(j = 0; j < n; j++)
//        scanf("%f", &b[j]);
}

//输出结果
void output(){
    int i;
    printf("Total iteration : %d", iteration);
    if(iteration > MAX_ITERATION) printf(", that is out of the limit of iteration!");
    printf("\n");

    for(i = 0; i < MAX_N; i++)
        printf("x[%d] is %f\n", i, result_x[i]);
}
//判断精度是否满足要求，满足要求则返回TRUE, 否则返回FALSE
bool tolerance(){
    int i;
    //有一个不满足误差的，返回FALSE
    for(i = 0; i < MAX_N; i++)
        if(result_x[i] - x[i] > TOLERANCE || x[i] - result_x[i] > TOLERANCE)
            return FALSE;
#ifdef DEBUG
    printf("TRUE From %d\n", pID);
  	fflush(stdout);
#endif
    return TRUE;
}
int main(int argc, char *argv[])
{
    MPI_Status status;
    int i, j;
    float sum;
    clock_t start_time, end_time;
    double total;

    MPI_Init(&argc, &argv);
    MPI_Barrier(MPI_COMM_WORLD);
    start_time = clock();
    MPI_Comm_rank(MPI_COMM_WORLD, &pID);
    MPI_Comm_size(MPI_COMM_WORLD, &pSize);

    n = pSize; //每个进程对应一个未知数
    if(!pID) input();

    //广播系数
    MPI_Bcast(a, MAX_A, MPI_FLOAT, 0, MPI_COMM_WORLD);
    //广播b
    MPI_Bcast(b, MAX_N, MPI_FLOAT, 0, MPI_COMM_WORLD);

    //初始化x的值
    for(i = 0; i < MAX_N; i++){
        x[i] = b[i];
        new_x[i] = b[i];
    }
    //当前进程处理的元素为该进程的ID
    i = pID;
    //迭代求x[i]的值
    do{
        //迭代次数加1
        iteration++;
        //将上一轮迭代的结果作为本轮迭代的起始值，并设置新的迭代结果为0
        for(j = 0; j < MAX_N; j++){
            x[j] = result_x[j];
            new_x[j] = 0;
            result_x[j] = 0;
        }
        //同步等待
        MPI_Barrier(MPI_COMM_WORLD);

        //求和
        sum = - a[i][i] * x[i];
        for(j = 0; j < MAX_N; j++) sum += a[i][j] * x[j];
        //求新的x[i]
        new_x[i] = (b[i] - sum) / a[i][i];

        //使用归约的方法，同步所有计算结果
        MPI_Allreduce(new_x, result_x, n, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);

        //如果迭代次数超过了最大迭代次数则退出
        if(iteration > MAX_ITERATION) {
            break;
        }
    }
    while(!tolerance()); //精度不满足要求继续迭代
    MPI_Barrier(MPI_COMM_WORLD);
    end_time = clock();
    //根进程负责输出结果
    if(!pID) output();

    //结束
    MPI_Finalize();

    total = (double)(end_time - start_time) / CLOCKS_PER_SEC ;
    printf("Running time of each CPU core is %f seconds \n", total);
    return 0;
}
//
// Created by 徐朝阳 on 2022/7/4.
//

