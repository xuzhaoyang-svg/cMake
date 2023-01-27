//
// Created by 徐朝阳 on 2022/7/23.
//
//实现一个共享栈，栈 s1 和栈 s2 共享一块存储区 V[]。
/*
 * 解题思路:将编号为 0 和 1 的两个栈存放于一个数组空间 V[m]中，栈底分别处 于数组的两端。
 * 当第 0 号栈的栈顶指针 top[0]等于-1 时该栈为空，当第 1 号栈 的栈顶指针 top [1]等于 m 时该栈为空。
 * 两个栈均从两端向中间增长。
 */
#define maxSize 100
#include "iostream"
using namespace std;
typedef struct {
    int top[2];//两个栈顶指针
    int bot[2];//两个栈低指针
    int elem[maxSize];
}DblStack;

//初始化
bool initStack(DblStack &s){
    s.bot[0]=s.top[0] = -1;
    s.bot[1] = s.top[1] = maxSize;
    return true;
}

//判空
bool isEmpty(DblStack &s , int i){
    return s.top[i] == s.bot[i];
}

//判满
bool isFull(DblStack &s){
    return s.top[0] + 1 == s.top[1];
}
//入栈
bool push(DblStack &s , int x ,int i){
    //判满
    if (isFull(s)) return false;
    if (i == 0)
        s.elem[++s.top[0]] = x;
    else
        s.elem[--s.top[1]] = x;
    return true;

}

//出栈
bool pop(DblStack &s , int &x ,int i){
    //判空
    if (isEmpty(s,i)) return false;
    if (i == 0)
        x = s.elem[s.top[0]--];
    else
        x = s.elem[s.top[1]++];
    return true;

}

int main(){
    DblStack s;
    int x;
    initStack(s);
    cout<<push(s,100,0)<<endl;
    cout<<pop(s,x,0)<<endl;
    cout<<"x = "<<x;

}