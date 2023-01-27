/*
 * @Author: xuzhaoyang
 * @Date: 2022-05-23 17:26:00
 * @LastEditors: xuzhaoyang
 * @LastEditTime: 2022-05-31 19:09:57
 * @FilePath: /DS/everday/LinList5_23.cpp
 * @Description: 学习数据结构
 * 
 */
#include<iostream>
using namespace std;
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode,*LinkList;

//头插法建立链表
LinkList List_HeadInsert(LinkList& L){
    ListNode *s;
    int x;
    L=new ListNode;
    L->next=NULL;
    cout<<"头插法input:"<<endl;
    cin>>x;
    while (x!=9999)
    {
        s= new ListNode;
        s->val=x;
        s->next=L->next;
        L->next=s;
        cin>>x;
    }
    return L;

}

//尾插法创建链表
LinkList List_TailInsert(LinkList& L){
    int x;
    L=new ListNode;
    L->next=NULL;
    ListNode *s,*r=L;//r为尾指针
    cout<<"尾插法input:";
    cin>>x;
    while (x!=9999)
    {
        s=new ListNode;
        s->val=x;
        r->next=s;
        r=s;
        cin>>x;
    }
    r->next=NULL;
    return L;
}


//递归正向打印链表
void PrintListF(LinkList& L){
    if(L==NULL){
        return;
    }
    cout<<L->val<<" ";
    PrintListF(L->next);
}


//递归逆向打印链表
void PrintListR(LinkList& L){
    if(L==NULL){
        return;
    }
    PrintListR(L->next);
    cout<<L->val<<" ";
}


//返回链表倒数第K个结点的值
int KthToLast(LinkList& L,int k){
    ListNode *left =L;
    ListNode *right = L;
    //right先向右移动K个位置
    while (--k)
    {
        right=right->next;
    }
    while (right->next!=NULL)
    {
        left = left->next;
        right = right->next;
    }
    return left->val;

}


//判断一个链表是否存在环(使用两个指针，一个快一个慢，一个一次走一步，一个一次走两步)
bool HasCycle(LinkList& L){
    ListNode* fast=L;
    ListNode* slow=L;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
        {
            return true;
        }

    }
    return false;
}


//删除链表中值为val的结点5/16
void ListDelete(LinkList& L, int val){
    ListNode *p=L,*pre=L;
    while (p!=NULL)
    {
        if (p->val==val)
        {
            ListNode* s=p;//用s指向p，p向后移动一步并将地址给到pre->next(抛弃p结点)，pre为p的前驱结点
            p=p->next;
            pre->next=p;
            delete s;//删除s
        }
        else{
            //p向后移动，pre向后移动
            pre=p;
            p=p->next;
        }

    }

}


// //5/16给定一个带头结点的非空链表L，返回链表的中间结点，如果有两个中间结点，则返回第二个中间结点。（快慢指针）
// int  MiddleNode(LinkList &L){
//   ListNode *slow=L;
//   ListNode *fast=L;
//   PrintListF(L);
//   while (slow != NULL&&fast->next != NULL)
//   {
//     slow=slow->next;
//     fast=fast->next->next;
//   }
//   cout<<slow->val;

// }

//5/17给定一个带头结点的链表翻转它
void ReverseList(LinkList &L){
    ListNode *p=L->next;
    ListNode *pre=L->next;
    ListNode *r=p->next;
    p->next=NULL;//反转后链表的链尾
    while (r!=NULL)
    {
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;//反转指针
    }
    L->next=p;//反转后的链表接到头结点

}

//找到两个链表的第一个相交结点
ListNode* GetIntersectionNode(LinkList &LA, LinkList &LB){
    if (LA == NULL||LB ==NULL)
    {
        cout<<"有空链表";
        return NULL;
    }
    int i=0;
    ListNode *pA=LA, *pB=LB;
    while (pA!=pB)
    {
        pA = pA == NULL ? LB : LA->next;
        pB = pB == NULL ? LA : LB->next;
        i++;
        cout<<i;
    }
    cout<<pA->val<<i;
    return pA;
}

int main(){
    LinkList L1,L2;
    ListNode *a;
    // a=new ListNode;
    L1=List_HeadInsert(L1);
    L2=List_TailInsert(L2);
    PrintListF(L1);
    PrintListF(L2);
    a = new ListNode;
    a=GetIntersectionNode(L1,L2);
    cout<<"相交的第一个结点值"<<a->val;

    // ReverseList(L1);

    // L2=List_TailInsert(L2);
    // PrintListF(L1);
    // MiddleNode(L1);
    // int  a=MiddleNode(L1);;

    // cout<<a;

    // ListDelete(L1,1);
    // PrintListF(L1);
    // PrintListR(L1);
    // PrintListF(L2);
    // PrintListR(L2);
    //int k=KthToLast(L1,3);//返回链表第倒数K个结点的值
    //cout<<"链表第倒数K个结点的值:"<<k;


}