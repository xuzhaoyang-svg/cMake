//
// Created by 徐朝阳 on 2022/8/27.
//
//删除顺序表所有值介于x和y之间的元素
#include "iostream"

using namespace std;
typedef struct {
    int *elem;
    int length;
}SeqList;

void deleteSeqList(SeqList &L,int x,int y){
    if (L.length == 0)return;
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] <= x || L.elem[i] >= y)
            L.elem[k++] = L.elem[i];
    }
    L.length = k;
}
void printSeqList(SeqList &L){
    if (L.length == 0)return;
    for (int i = 0; i < L.length; i++) {
        cout<< L.elem[i]<<" "<<endl;
    }
    cout<<"长度为："<<L.length<<endl;
}
int main(){
    SeqList L ;
    L.elem = new int[5];
    L.length = 5;
    for (int i = 0; i < L.length; i++) {
        L.elem[i] = i;
    }
    printSeqList(L);
    deleteSeqList(L,1,4);
    printSeqList(L);
}