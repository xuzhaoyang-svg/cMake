//
// Created by 徐朝阳 on 2022/6/11.
//
//共享栈
#include "iostream"
using namespace std;
#define maxSize 10

typedef struct {
    int top[2];//栈顶指针两个
    int bot[2];//栈低指针两个
    int elem[maxSize];
}shareStack;

//初始化
bool initStack(shareStack &s){
    s.bot[0]=s.top[0]=-1;//左部分栈
    s.bot[1]=s.top[1]=maxSize;//右部分栈
    return true;
}
//判空
bool isEmpty(shareStack &s,int i){
    return s.bot[i]==s.top[i];//i=0或1，随便验证哪一边的栈就知道这个共享栈空不空。
}
//判满
bool isFull(shareStack &s){
    return s.top[0]+1==s.top[1];//根据左右两端栈的栈顶指针，看是不是"差一个数"就相等。
}
//入栈
bool push(shareStack &s ,int x,int i){
    if (isFull(s)){
        return false;
    }
    if (i==0){
        s.elem[++s.top[0]]=x;
    }
    else{
        s.elem[--s.top[1]]=x;
    }
    return true;
}
//出栈
bool pop(shareStack &s ,int &x,int i){
    if (isEmpty(s,i)){
        return false;
    }
    if (i==0){
        x=s.elem[s.top[0]--];
    } else{
        x=s.elem[s.top[1]++];
    }
    return true;
}
int main(){
    shareStack S;
    int L=1,R=2,e=0;
    initStack(S);
    push(S,L,0);
    push(S,R,1);
    pop(S,e,0);
    cout<<"Lift:"<<e<<endl;
    pop(S,e,1);
    cout<<"Right:"<<e<<endl;

}