//
// Created by 徐朝阳 on 2022/6/1.
//
#include "iostream"
using namespace std;
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode,*LinkList;

LinkList &createListR(int finish){
    ListNode *L=new ListNode;
    L->next=NULL;
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
void printLinList(LinkList& L) {
    L = L->next;
    if (L == NULL)
        cout << "空链表" << endl;
    cout << "打印链表" << endl;
    while (L != NULL) {
        cout << L->val << endl;
        L = L->next;
    }

}
//将两个升序链表合并为一个
ListNode *mergeTwoLists(LinkList &L1,LinkList &L2){
    ListNode *p=new ListNode ;//合并后的链表的头结点
    p->next=NULL;
    ListNode *s=p;//S指针遍历两个链表
    while (L1 != NULL && L2 != NULL){
        if (L1->val<L2->val){
            s->next=L1;
            L1=L1->next;
        }
        else{
           s->next=L2;
           L2=L2->next;
        }
        s=s->next;
    }
    s->next = (L1 == NULL ?L2:L1);//剩余收尾
    //释放开始时创建的头结点
    ListNode *temp=p;//指针p的地址传递给temp
    p=p->next;//指向s指针，指的结点，p已经等于p的下一个结点的地址
    delete temp;//释放p的地址
    return p;
}

int main(){

    ListNode *p1,*p2;
    p1= createListR(9);
//    printLinList(p1);
    p2= createListR(1);
    ListNode *m;
    m= mergeTwoLists(p1,p2);
    printLinList(m);

}