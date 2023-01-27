//
// Created by 徐朝阳 on 2022/7/20.
//
//给定一个带头结点的单链表，翻转链表

#include "iostream"
using namespace std;

typedef struct node {
    int val;
    struct node *next;
}ListNode,*List;

ListNode *createList(int end){
    //创建头结点
    ListNode *L = new ListNode;
    ListNode *rear = L;
    int x;
    cin >> x;
    while (x != end){
        //创建新结点
        ListNode *newNode = new ListNode ;
        newNode->val = x;
        rear->next = newNode;
        rear = newNode;
        cin>>x;
    }
    return L;
}
//翻转链表
//方法一：头插法，从链表的首元结点开始，用头插法将其后的结点依次插入到它前面。
void reverseList(List &L){
    ListNode *p , *r;
    p = L->next;//p指向即将要摘下的结点
    L->next = NULL;
    while (p != NULL){
        r = p->next;//r暂时替p接管链表未翻转部分
        p->next = L->next;//摘下结点，头插法，插到前面，建立后索引
        L->next = p;//建立前索引,与头结点连接
        p = r;//继续指向即将要摘下的结点
    }
}
/*
 * 方法二：反转指针法——初始化时，让首元结点的指针为 NULL，
 * 从第二个结点开始，让结点的指针指向它的前驱，最后再将尾结点链到头结点。
 */
void reverseList2(List &L){
    ListNode *p = L->next;
    ListNode *pre = L->next;
    ListNode *r = p->next;
    p->next = NULL;//新的的链尾
    while (r != NULL){
        pre = p;//p移动之前要留下记录，记录将要摘下结点的前驱结点
        p=r;//移动到当前将要翻转的结点
        r = r->next;//移动到下一个要翻转的结点
        p->next = pre;//指针翻转。让结点的指针指向它的前驱。
    }
    L->next = p;//翻转后的链表接到头结点。最后再将尾结点链到头结点
}
void printList(List &L){
    ListNode *p=L;
    if (p != NULL){
        cout<<p->val<<"  ";
        printList(p->next);
    }

}
int main(){
    List L;
    L= createList(0);//1 2 3 0
    cout<<"打印链表：" ;
    printList(L->next);
    reverseList(L);
    cout<<"打印链表：" ;
    printList(L->next);
    reverseList2(L);
    cout<<"打印链表：" ;
    printList(L->next);

}