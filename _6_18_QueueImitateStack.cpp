//
// Created by 徐朝阳 on 2022/6/18.
//

#include "iostream"
using namespace std;
#define maxSize 5

typedef struct {
    int elem[maxSize];
    int front=0,rear=0;
    int size=0;
}SqQueue;

bool isEmpty(SqQueue &q){
    return q.size==0;
}
bool isFull(SqQueue &q){
    return q.size==maxSize;
}
bool enQueue(SqQueue &q,int x){
    if (isFull(q)){
        return false;
    }
    q.elem[q.rear]=x;
    q.rear=(q.rear+1)%maxSize;
    q.size++;
    return true;
}
bool deQueue(SqQueue &q,int &e){
    if (isEmpty(q)){
        return false;
    }
    e=q.elem[q.front];
    q.front=(q.front+1)%maxSize;
    q.size--;
    return true;
}
//Imitata Stack
bool push(SqQueue &q,int x){
    if (isFull(q)){
        return false;
    }
    int y;
    enQueue(q,x);
    for (int i = 0; i < q.size-1; i++) {
        deQueue(q,y);
        enQueue(q,y);
    }
    return true;
}
bool pop(SqQueue &q ,int &e){
    if (isEmpty(q)){
        return false;
    }
    deQueue(q,e);
    return true;
}
bool stackEmpty(SqQueue &q){
    return isEmpty(q);
}
int main(){
    int e;
    SqQueue q;
    push(q,3);
    push(q,4);
    pop(q,e);
    //e=4
    cout<<e<<endl;


}