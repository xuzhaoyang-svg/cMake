//
// Created by 徐朝阳 on 2022/6/9.
//

//链栈相当于无头结点的采用头插法建立的单链表
#include "iostream"
using namespace std;
typedef struct node{
    int val;
    struct node *next;
}LinkNode,*LinkStack;

//初始链栈栈
void initStack(LinkStack &s){
    s=NULL;
}

//判空
bool isEmpty(LinkStack &s){
    return s==NULL;
}

//压栈push,不需要判空
void push(LinkStack &s,int x){
    LinkNode *p=new LinkNode ;
    p->val=x;
    p->next=s;//p指向s结点
    s=p;//p变为第一个结点

}
//出栈pop，需要判空
bool pop(LinkStack &s,int &e){
    if (isEmpty(s)){
        return false;//栈为空返回false，不再执行剩下代码
    }
    //出栈就要删除结点
    LinkNode *p=s;//s指向的地址赋给p，s始终指向第一个结点
    e=s->val;//取出当前值
    s=s->next;//s指针更新，指向下一结点，更新地址，抛弃原来地址空间
    delete p;//删除s原来的地址空间
    return true;
}
//获取栈顶元素getTop，需要判空
bool getTop(LinkStack &s,int &e){
    if (isEmpty(s)){
        return false;
    }
    e=s->val;
    return true;
}

int main(){
    LinkStack s;
    int e;
    //初始化栈
    initStack(s);
    cout<<"isEmpty:"<<isEmpty(s)<<endl;
    //给栈中压入5个元素，0，1，2，3，4
    for (int i = 0; i < 5; ++i) {
        push(s,i);
    }
    pop(s,e);
    cout<<"pop:"<<e<<endl;
    getTop(s,e);
    cout<<"getTop:"<<e<<endl;
}