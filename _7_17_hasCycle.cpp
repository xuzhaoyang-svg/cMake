//
// Created by 徐朝阳 on 2022/7/17.
//
//判断一个链表是否有环
#include "iostream"
using namespace std;

typedef struct node {
    int val;
    struct node *next;
}ListNode , *LinkList;

ListNode *createList(int end){
    //创建头结点
    ListNode *L=new ListNode ;
}
/*
 * 定义两个指针一块一慢。
 * 慢指针每次只移动一步，快指针每次移动两步。
 * 如果在移动的过程中，快指针追上慢指针并相遇，就说明该链表为环形链表。
 */
bool hasCycle(LinkList &L){
    ListNode *slow = L;
    ListNode *fast = L;
    while (fast != NULL && fast->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast == slow){
            return true;//存在环
        }
    }
    return false;//不存在环
}