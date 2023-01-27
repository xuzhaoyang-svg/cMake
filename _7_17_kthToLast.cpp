//
// Created by 徐朝阳 on 2022/7/17.
//
//返回链表倒数第K个结点的值
#include "iostream"
using namespace std;

typedef struct node{
    int val;
    struct node *next;
}ListNode;

//尾插法
ListNode *createList(int end){
    //创建头结点
    ListNode *L = new ListNode ;
    ListNode *rear=L;
    int x;
    cin >> x;
    while (x != end){
        //创建新结点
        ListNode *newNode = new ListNode ;
        newNode->val = x;
        rear->next = newNode;//放到表尾
        rear = newNode;//变为表尾结点
        cin >> x;
    }
    return L;
}

//返回链表倒数第K个结点的值
/*
 * 使用双指针。两个指针都指向表头，第一个q指针先走K步
 * 接着两个p、q同时移动，当q为空时所指结点即为倒数第K个结点
 */
int kthToLast(ListNode *L , int k){
    ListNode *p = L ;
    ListNode *q = L ;
    //指针q先向后移动k个位置
    while (k--){
        q = q->next;
    }
    while (q != NULL){
        q = q->next;
        p = p->next;
    }
    return p->val;
}

int main(){
    ListNode *L;
    L = createList(0);//1 2 3 0
    cout<<"返回倒数第K个结点:"<<kthToLast(L , 2);
}
