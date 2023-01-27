//
// Created by 徐朝阳 on 2022/7/22.
//
//将两个顺表合并为一个
#include "iostream"
#define maxSize 100
typedef struct {
    int elem[maxSize];
    int length;
}SeqList;
using namespace std;
//创建顺序表
bool createSeqList(SeqList &SL,int end){
    int x,i=0;
    cin >> x;
    while (x != end){
        SL.elem[i++] = x;

        cin >> x;
    }
    SL.length = i;
    return true;
}
//合并两个为一个，有序；类似归并排序
/*
 * 解题思路:两两比较表 A 和表 B 的元素大小，将二者之中更小的或者是相等的元 素赋值到表 C 中，同时对应表与表 C 的指针都加 1。
 * 当表 A 或表 B 其中一个表已 经遍历结束，那么直接把另一个表剩下的部分接到表 C 后面。整个过程的思路和 合并有序链表是相同的。
 */
bool Merge(SeqList &A ,SeqList &B ,SeqList &C){
    if (A.length + B.length > C.length) return false ;//C无法容纳
    //两两比较，小的入C
    int i=0,j=0,k=0;
    while (i < A.length && j < B.length){
        if (A.elem[i] <= B.elem[j]){
            C.elem[k++] = A.elem[i++];
        } else{
            C.elem[k++] = B.elem[j++];
        }
    }
    //将两者没比较完的直接连接到C后面
    while (i < A.length) C.elem[k++] = A.elem[i++];
    while (j < B.length) C.elem[k++] = B.elem[j++];
    C.length = k;//给C的长度赋值
    return true;
}
void printSeqList(SeqList &SL){
    int i = 0;
    while (SL.length--){
        cout<<SL.elem[i++]<<" ";
    }
    cout<<endl;
}
int main(){
    SeqList A , B , C;
    cout<<createSeqList(A,0)<<endl;//1 2 3 0
    cout<<createSeqList(B,0)<<endl;//1 4 5 6 0
    cout<<Merge(A,B,C)<<endl;
    printSeqList(A);printSeqList(B);printSeqList(C);
}
