//
// Created by 徐朝阳 on 2022/6/9.
//

#include "iostream"
#define maxSize 10
using namespace std;
typedef struct {
    int elem[maxSize];
    int pop=-1;
}SeqStack;

//判空
bool isEmpty(SeqStack &S){
    return S.pop==-1;
}
//判满
bool isFull(SeqStack &S){
    return S.pop==maxSize-1;
}
//元素进栈
bool push(SeqStack &S,int x){
    if (isFull(S)){
        return false;
    }
    S.elem[++S.pop]=x;
    return true;
}
//元素出栈
bool pop(SeqStack &S,int &e){
    if (isEmpty(S)){
        return false;
    }
    e=S.elem[S.pop--];
}
int main(){
    SeqStack S;
    int e;
    cout<<"isEmpty:"<<isEmpty(S)<<endl;
    cout<<"isFull:"<<isFull(S)<<endl;
    for (int i = 0; i < maxSize; ++i) {
        push(S,i);

    }
    for (int i = 0; i < maxSize; ++i) {
        pop(S,e);
        cout<<"popTest:"<<e<<endl;
    }

}