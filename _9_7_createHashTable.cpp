//
// Created by 徐朝阳 on 2022/9/7.
//创建哈希表，处理冲突方法使用线性探测再散列，计算查找成功平均查找长度
#include "iostream"
using namespace std;

int createAndCountASLSuccess(int ht[],int arr[],int m,int n,int p){
    //哈希表预处理
    for (int i = 0; i <m ; i++) {
        ht[i] = -1;
    }
    int res = 0;//总查找长度

    for (int i = 0; i < n; i++) {
        int count = 0;//计数器
        int loc = arr[i]%p;//计算一次位置count+1
        count ++;
        //定位
        while (ht[loc] != -1){
            loc = (loc + 1) % m;
            count ++;
        }
        //赋值
        ht[loc] = arr[i];
        res +=count;
    }
    return res/n;
}
float countUnSuccess(int ht[],int m,int p){
    float res = 0;//总查找长度
    for (int i = 0; i < p; i++) {
        int val =ht[i];
        int count = 1;//计数器查找一次+1
        int j = i;
        while (val != -1 ){
            j = (j+1)%m;
            val = ht[j];
            count++;
        }
        res += count;
    }
    return res/p;
}
int main(){
    int ht[10];
    int arr[8] ={19,13,20,21,23,27,26,30};
    cout<<createAndCountASLSuccess(ht,arr,10,8,7)<<endl;
    cout<<countUnSuccess(ht,10,7);
}
