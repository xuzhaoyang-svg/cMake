//
// Created by 徐朝阳 on 2022/7/22.
//
//实现一个顺序栈，并实现判空、判满、Push、pop
/*
 * 解题思路:建立一个顺序栈的结构体 SqStack，结构体内包含作为栈的容纳空间 的一个数组和另一个栈顶指针 top。
 * 首先对于一个栈我们要有判空和判满的操作;
 * 在 push 操作前，程序要先检查栈是否为满，满的话就无法入栈;
 * 在 pop 操作前， 我们要先检查栈是否为空，空的话就无法出栈。
 */
#include "iostream"
#define maxSize 100
using namespace std;
typedef struct {
    int elem[maxSize];
    int top = -1;
}SqStack;
//判空
bool isEmpty(SqStack &s){
    return s.top == -1;
}
//判满
bool isFull(SqStack &s){
    return s.top == maxSize - 1;
}
//进栈
bool push(SqStack &s,int x){
    if (isFull(s)) return false;
    else
        s.elem[ ++ s.top] = x;
    return true;
}
//出栈
bool pop(SqStack &s,int &x){
    if (isEmpty(s)) return false;
    else
        x = s.elem[s.top--];
    return true;
}
int main(){
    SqStack s;
    int x;
    cout<<push(s,100) <<endl;
    cout<< pop(s,x)<<endl;
    cout<<x;
}