//
// Created by 徐朝阳 on 2022/8/12.
//
//顺序表的元素为整型，第一个元素为key，小于key的放到其前面，大于的放到后面。参考快速排序，一趟划分。key为基准值
#include "iostream"
using namespace std;

void Partition(int *arr ,int len){
    //顺序表arr,长度len
    int key = arr[0];
    int i = 0;//i指针从前往后遍历
    int j = len - 1;//j指针从后往前遍历
    while (i < j){
        while (i < j && arr[j] >= key ) j--;//逆向扫描找到小于key的
        if ( i < j){//小于基准值交换到左边
            arr[i] = arr[j];
            i++;
        }
        while (i < j && arr[i] <= key ) i++;//正向扫描找到大于key的
        if ( i < j){//大于基准值交换到右边
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = key ;//key归位
}
int main(){
    int arr[5]={19,13,14,21,23};
    Partition(arr,5);
    for (int i = 0; i < 5; i++) {
        cout<<arr[i]<<"  ";
    }
}