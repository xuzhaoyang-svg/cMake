//
// Created by 徐朝阳 on 2022/7/16.
//
//给定一个长度为length的数组arr，一个值val，原地移除所有数值等于val的元素，返回新的数组长度
#include "iostream"
using namespace std;

int removeElements(int *arr,int length, int val){
    int left=0,right=0;//定义双指针，right负责遍历arr，left负责维护arr
    while (right<length){
        if (!(arr[right] == val)){
            arr[left] = arr[right];
            left++;
        }
        right++;
    }
    return left;
}

int main(){
    int arr[5]={1,1,2,2,3};
    //原地移除值等于2的元素
    cout<<"移除后的长度： "<<removeElements(arr,5,2);
}
