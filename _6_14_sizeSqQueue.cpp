//
// Created by 徐朝阳 on 2022/6/14.
//
//循环队列，使用Size变量判断队空队满

#include "iostream"
using namespace std;

#define maxsize 2
typedef struct {
    int elem[maxsize];
    int front=0,rear=0;
    int size=0;
}SqQueue;
//判满
bool isFull(SqQueue &q){
    return q.size==maxsize;
}
//判空
bool isEmpty(SqQueue &q){
    return q.size==0;
}
//入队
bool enQueue(SqQueue &q,int x){
    if (isFull(q)){
        return false;
    }
    q.elem[q.rear]=x;
    q.rear=(q.rear+1)%maxsize;
    q.size++;
    return true;
}
//出队
bool deQueue(SqQueue &q,int &e){
    if (isEmpty(q)){
        return false;
    }
    e=q.elem[q.front];
    q.front=(q.front+1)%maxsize;
    return true;

}
//队长度
int getLength(SqQueue &q){
    return q.size;
}
int main(){
    SqQueue q;
    int x=9,e;
    enQueue(q,x);
    deQueue(q,e);
    cout<<e;
}