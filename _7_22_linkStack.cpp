//
// Created by 徐朝阳 on 2022/7/22.
//
//实现一个链式栈，并实现判空、push、pop、getTop 等操作。
/*
 * 解题思路:作为一个链式栈，首先因为链表的特性所以它不会有栈满的情况，
 * 其 次基于栈先进后出的特性，所以我们也不需要为链栈专门设置一个头结点。
 * 为新入栈的元素申请一个结点 p 并且把它作为链头，执行出栈操作时只需要将栈顶指针 s 送向 p 结点的 next，同时释放掉 p 结点。
 */
#include "iostream"
using namespace std;
typedef struct node{
    int val;
    struct node *next;
}LinKNode,*LinkList;
//初始化，栈顶指针置空
void inintStack(LinkList &s){
    s = NULL;
}
//判空
bool isEmpty(LinkList &s){
    return s == NULL;
}
//进栈不需要判满
void push(LinkList &s,int x){
    LinKNode *p = new LinKNode ;
    p->val = x;
    p->next = s;//插到栈顶
    s = p;//指针再次指向栈顶
}
//出栈要判空
bool pop(LinkList &s){
    if (isEmpty(s)) return false;
    LinKNode *p = s;
    s = s->next;
    delete p;
    return true;
}
//获取栈顶元素
bool getTop(LinkList &s,int &x){
    if (isEmpty(s)) return false;
    else
        x = s->val;
        return true;
}
int main(){
    LinkList s;
    int x;
    //必须先要初始化
    inintStack(s);
    push(s,100);
    cout<<getTop(s,x)<<endl;
    cout<<x<<endl;
    cout<<pop(s)<<endl;
    cout<<isEmpty(s)<<endl;
    cout<<getTop(s,x)<<endl;

}