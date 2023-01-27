//
// Created by 徐朝阳 on 2022/5/31.
//
#include<iostream>
using namespace std;
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode,*LinkList;

LinkList &createListR(int finish){
    ListNode *L=new ListNode;
    ListNode *r=L;//指向链尾
    int x;
    cout<<"请输入："<<endl;
    cin>>x;
    while (x!=finish){
        ListNode *p=new ListNode ;
        p->val=x;
        r->next=p;//新结点加到链尾
        r=p;//r指向链尾
        cin>>x;

    }
    r->next=NULL;
    return L;

}

LinkList &creatListF(int finish){
    ListNode *L=new ListNode ;
    L->next=NULL;
    int x=0;
    cin>>x;
    cout<<"头插法："<<endl;
    while (x != finish){
        ListNode *p=new ListNode;
        p->val=x;
        p->next=L->next;
        L->next=p;
        cin>>x;
    }
    return L;
}
void printLinList(LinkList& L){
    L=L->next;
    if (L==NULL)
        cout<<"空链表"<<endl;
    cout<<"打印链表"<<endl;
    while (L!=NULL){
        cout<<L->val<<endl;
        L=L->next;
    }

}
//第一个数值相等的结点
ListNode *getIntersectionNode(LinkList& pHead1,LinkList& pHead2){
    if (!pHead1 || !pHead2)    return nullptr;
    auto *p1=new ListNode ;
    auto *p2=new ListNode ;
    p1 = pHead1;p2 = pHead2;
    p1=p1->next;
    p2=p2->next;
    while(p1->val!= p2->val) {
        p1 = (p1 ? p1->next : p2);
        p2 = (p2 ? p2->next : p1);
    }
    return p2;






}
int main(){
    ListNode *p1,*p2;
    p1= creatListF(0);
    printLinList(p1);
//    p2= createListR(0);
//    printLinList(p2);
//    ListNode *get=new ListNode ;
//    get=getIntersectionNode(p1,p2);
//    cout<<get->val;

}