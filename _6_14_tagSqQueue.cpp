//
// Created by 徐朝阳 on 2022/6/14.
//
//循环队列，通过增设tag数据成员以区分队空和队满
#include "iostream"
using namespace std;

#define maxSize 3
typedef struct {
   int elem[maxSize];
   int front=0,rear=0;
   int tag=0;
}SqQueue;

//判满
bool isFull(SqQueue &q){
    return q.tag==1;                 //这里不同
}
//判空
bool isEmpty(SqQueue &q){
    return q.rear==q.front&&q.tag==0;//这里不同
}
//入队
bool enQueue(SqQueue &q, int x){
    if (isFull(q)){
        return false;
    }
    q.elem[q.rear]=x;
    q.rear=(q.rear+1)%maxSize;
    if (q.rear==q.front){
        q.tag=1;
    }
    return true;
}
//出队
bool deQueue(SqQueue &q,int &e){
    if (isEmpty(q)){
        return false;
    }
    e=q.elem[q.front];
    q.front=(q.front+1)%maxSize;
    q.tag = 0;//tag置为0，表示不满
    return true;
}
//队的长度
int getLength(SqQueue &q){
    if (q.tag==1){
        return maxSize;
    }
    return (q.rear-q.front+maxSize)%maxSize;
}

int main(){
    SqQueue q;
    int x=6,e;
    enQueue(q,x);
    cout<<"length: "<<getLength(q)<<endl;
    deQueue(q,e);
    cout<<"length: "<<getLength(q)<<endl;
    cout<<"e: "<<e;
}