//
// Created by 徐朝阳 on 2022/7/20.
//
//给定一个带有头结点的非空单链表 L，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
#include "iostream"
using namespace std;

typedef struct node {
    int val;
    struct node *next;
}ListNode,*List;
//尾插法创建带头结点单链表
ListNode *createNode(int end){
    ListNode *L = new ListNode ;
    ListNode *rear = L;
    int x;
    cin >> x;
    while (x != end){
        ListNode *newNode = new ListNode ;
        newNode->val = x;
        rear->next = newNode;//放到表尾
        rear=newNode;//设为尾结点
        cin >> x;
    }
    return L;
}
//返回中间结点
/*用双指针法，一个 left 指针每次走一步，一个 right 指针每次走两步，
 * 当 right->next 为 NULL 时，说明是一个奇数结点数的单链表，此时 left 所指结点就是中间结点;
 * 当 right 为 NULL 时，说明是一个偶数结点数的单链表， 此时 left 所指结点就是第二个中间结点。
 */

ListNode *middleNode(List &L){
    ListNode *left = L->next;//跳过头结点，头结点val=0
    ListNode *right = L->next;
    while (right != NULL && right->next != NULL){
        left = left->next;
        right = right->next->next;

    }
    return left;
}

int main(){
    ListNode *L,*middle;
    L= createNode(0);//1 2 3 4 5 6 0
    middle= middleNode(L);
    cout<<middle->val;
}
