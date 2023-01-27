//
// Created by 徐朝阳 on 2022/7/21.
//
//找到两个链表相交的起始结点，相交结点后是一个结点
#include "iostream"
using namespace std;

//创建链表
typedef struct node{
    int val;
    struct node *next;
}ListNode,*List;
ListNode *createList(int end){
    ListNode *L = new ListNode ;
    int x;
    cin>>x;
    while (x != end){
        ListNode *newNode = new ListNode ;
        newNode->val = x;
        newNode->next = L->next;
        L->next = newNode;

        cin >>x;
    }
    return L;
}
void printList(List &L){
    ListNode *p=L;
    if (p != NULL){
        cout<<p->val;
        printList(p->next);
    }
}
//解题思路:算出两个链表的长度，然后把长一点的链表走到跟短的链表一样长， 然后同时一起走就可以找到相交的结点。
ListNode *getIntersectionNode(List &L1,List &L2){
    int length1 = 0;
    int length2 = 0;
    ListNode *p = L1;
    ListNode *q = L2;
    while (p != NULL) {p = p->next; length1++;}
    while (q != NULL) {q = q->next; length2++;}

    int len = length1 - length2;
    int i = abs(len);
    p = L1;
    q = L2;
    //把长的链表走到和短的一样长
    while (i--){
        if (len >= 0)//p较长
            p = p->next;
        else        //q较长
            q = q->next;
    }
    //相交结点后的结点都是相同的
    //找到相交起始结点
    while (p != q){
        p = p->next;
        q = q->next;
    }
    return p;

}
int main(){
    List L1,L2,L3;
    L1= createList(0);//1 0
    L2= createList(0);//1 0

    L3= getIntersectionNode(L1,L2);
    cout<<L3->val;
}