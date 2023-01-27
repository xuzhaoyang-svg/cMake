//
// Created by 徐朝阳 on 2022/7/16.
//

#include "iostream"
using namespace std;

typedef struct node{
    int val;
    struct node *next;
}LinkNode;

//头插法
LinkNode *createListF(int end){
    //创建头结点
    LinkNode *L=new LinkNode ;
    L->next=NULL;
    int x;
    cin>>x;
    while (x != end){
        //创建新结点
        LinkNode *newNode = new LinkNode ;
        newNode->val=x;
        newNode->next=L->next;
        L->next=newNode;
        cin>>x;
    }
    return L;
}
//尾插法
LinkNode *createListR(int end){
    LinkNode *L=new LinkNode ;
    LinkNode *rear=L;
    int x;
    cin>>x;
    while (x != end){
        LinkNode *newNode = new LinkNode ;
        newNode->val = x;
        rear->next=newNode;//新结点添加到尾部
        rear=newNode;//新结点变成表尾
        cin>>x;
    }
    return L;
}

//正向打印链表
int i=1;
void printList1(LinkNode *L){
    cout<<"递归层数: "<<i++;
    LinkNode *p=L;
    if (p != NULL){
        cout<<"当前输出的结点："<<p->val<<"  "<<endl;
        printList1(p->next);
    }
    cout<<"返回上一层"<<endl;
}//也可使用循环

//反向打印链表
void printList2(LinkNode *L){
    cout<<"递归层数： "<<i++;
    LinkNode *p=L;
    if (p != NULL){
        printList2(p->next);
        cout<<"当前输出的结点："<<p->val<<"  "<<endl;
    }
    cout<<"返回上一层"<<endl;
}//也可使用栈

int main(){
    LinkNode *LF,*LR;
    LF= createListF(0);//1 2 0
    LR= createListR(0);
    cout<<"正向："<<endl;
    printList1(LF);
    printList1(LR);
    cout<<endl;
    cout<<"反向："<<endl;
    printList2(LF);
    printList2(LR);
}