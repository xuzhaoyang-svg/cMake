//
// Created by 徐朝阳 on 2022/7/18.
//
//删除链表中所有值为target的结点
/*
 * 双指针法
 * 指针P用来遍历链表，pre指向p的前一个结点
 * 当遍历到一个值为target的结点时，把它交给临时指针s，然后将结点释放掉
 */
#include "iostream"
using namespace std;
typedef struct node{
    int val;
    struct node *next;
}ListNode,*List;

ListNode *createList(int end){
    ListNode *L=new ListNode ;
    ListNode *rear = L;
    int x;
    cin>>x;
    while (x != end){
        ListNode *newNode = new ListNode ;
        newNode->val=x;
        rear->next=newNode;
        rear=newNode;
        cin>>x;
    }
    return L;
}

void listRemove(List &L,int target){
    if (L == NULL) return;
    ListNode *p=L;
    ListNode *pre=L;
    while (p != NULL){

        if (p->val == target)
        {
            ListNode *s=p;
            pre->next=p->next;
            delete s;
        } else{
            pre=p;
            p=p->next;
        }
    }
}

//递归方法
void listRemove2(List &L , int target){
    ListNode *p;
    if (L == NULL) return;//递归的边界条件，链表走到尾
    if (L->val==target){
        p=L;
        L=L->next;
        delete p;
        listRemove2(L,target);
    } else{
        listRemove2(L->next,target);
    }
}

//递归打印链表
void printList(List &L){
    if (L!=NULL){
        cout<<L->val<<"  ";
        printList(L->next);
    }
}
int main(){
    List L;
    L= createList(0);//1 2 3 4 5 0
    printList(L);
    cout<<endl;
    listRemove(L,1);
    printList(L);
    cout<<endl;
    listRemove2(L,0);
    printList(L);
}