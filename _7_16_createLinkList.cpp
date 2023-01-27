//
// Created by 徐朝阳 on 2022/7/16.
//

//使用头插法和尾插法创建带头结点的链表
#include "iostream"
using namespace std;
typedef struct node{
    int val;
    struct node *next;
}ListNode;

//头插法
ListNode *createListF(int end){
    //创建头结点
    ListNode *L= new ListNode ;
    L->next=NULL;
    int x;
    cin>>x;//以end为结束标识
    while (x != end){
        ListNode *newNode = new ListNode ;
        newNode->val=x;
        newNode->next=L->next;
        L->next=newNode;
        cin>>x;//以end为结束标识
    }
    return L;//返回头结点
}

//尾插法
ListNode *createListR(int end){
    //创建头结点
    ListNode *L=new ListNode ;
    ListNode *rear=L;
    int x;
    cin>>x;
    while (x != end) {
        ListNode *newNode = new ListNode;
        newNode->val = x;
        rear->next=newNode;//新结点添加到表尾
        rear=newNode;//新结点变成表尾
        cin>>x;
    }
    return L;
}

int main(){
    ListNode *LF,*LR;
    cout<<"头插法：";
    LF = createListF(0);//1 2 3 4 5 0
    cout<<"尾插法：";
    LR = createListR(0);
}
