//
// Created by 徐朝阳 on 2022/6/14.
//

#include "iostream"
using namespace std;

//循环队列，通过牺牲一个单元来区分队空和队满
#define maxSize 3
typedef struct {
    int elem[maxSize];
    int front=0, rear=0;
}SqQueue;

//判满
bool isFull(SqQueue &q){
    return (q.rear+1)%maxSize == q.front;//牺牲了一个空间，rear已经指向了最后一个位置，还要验证这个位置的后一个位置是否与对头指针相等
}

//判空
bool isEmpty(SqQueue &q){
    return q.rear==q.front;
}

//进队
bool enQueue(SqQueue &q, int x){
    if (isFull(q)){
        return false;
    }
    q.elem[q.rear]=x ;
    q.rear=(q.rear+1)%maxSize;
    return true;
}

//出队
bool deQueue(SqQueue &q, int &e){
    if (isEmpty(q)){
        return false;
    }
    e=q.elem[q.front];
    q.front=(q.front+1)%maxSize;
    return true;
}

//队大小
int getSize(SqQueue &q){
    return (q.rear-q.front+maxSize)%maxSize;
}

int main(){
    SqQueue q;
    int x=1,e;
    enQueue(q,x);
    cout<<"Size: "<<getSize(q)<<endl;
    deQueue(q,e);
    cout<<"Size: "<<getSize(q)<<endl;
    cout<<"e: "<<e<<endl;
}