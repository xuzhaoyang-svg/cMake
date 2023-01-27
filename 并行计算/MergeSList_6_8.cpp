//
// Created by 徐朝阳 on 2022/6/8.
//

#include "iostream"

using namespace std;
#define maxSize 100
typedef struct sList{
    int elem[maxSize];
    int length;
}SeqList;

bool Merge(SeqList &A,SeqList &B,SeqList &C){
    if (A.length+B.length+C.length>maxSize)//顺序表C无法容纳
        return false;
    int i=0,j=0,k=0;
    while (i<A.length&&j<B.length)
        if (A.elem[i]<B.elem[j])
            C.elem[k++]=A.elem[i++];//先用后加
        else
            C.elem[k++]=B.elem[j++];

        //将二者剩余没有比完部分插到C顺序表后面
    while (i<A.length)
        C.elem[k++]=A.elem[i++];
    while (j<B.length)
        C.elem[k++]=B.elem[j++];

    C.length=k;//给C的长度赋值
    cout<<C.length<<endl;
    return true;
}

void createSeqList(SeqList &L,int finish){
    int x=0,i=0;
    cout<<"创建顺序表:"<<endl;
    cin>>x;
    while(x!=finish&&i<maxSize){
        L.elem[i++]=x;
        cin>>x;
    }
    L.length=i;
}

void printSeqList(SeqList &L){
    int i=0;
    cout<<"printSeqList:"<<endl;
    while (i<L.length){
        cout<<L.elem[i++]<<endl;
    }
}
int main(){
    SeqList A,B,C ;
    C.length=0;//很重要
    createSeqList(A,0);
    createSeqList(B,0);
    //合并两个顺序表
    Merge(A,B,C);
    printSeqList(A);
    printSeqList(B);
    printSeqList(C);

}