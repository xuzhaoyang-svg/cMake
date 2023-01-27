//
// Created by 徐朝阳 on 2022/7/21.
//
//将两个升序链表合并为一个新的升序链表返回，无头结点
#include "iostream"
using namespace std;

typedef struct node{
    int val;
    struct node *next;
}ListNode,*List;
ListNode *createList(int end){
    ListNode *L = new ListNode ;
    L->next = NULL;
    int x;
    cin>>x;
    while (x != end){
        ListNode *newNode = new ListNode ;
        newNode->val = x;
        newNode->next = L->next;
        L->next = newNode;
        cin >> x;
    }
    return L;
}

/*解题思路:递归，如果 LA 或者 LB 一开始就是空链表，那么没有任何操作需要合 并，所以我们只需要返回非空链表。
 * 否则，我们要判断 LA 和 LB 哪一个链表的头结点的值更小，然后递归地决定下一个添加到结果里的结点。
 * 如果两个链表有一个为空，递归结束。
 */
ListNode *mergeTwoList(List &L1 , List &L2){
    if (L1 == NULL) return L2;
    else if (L2 == NULL )return L1;
    else if (L1->val < L2->val){
        //L1结点加入新链表，继续比较下一个
        L1->next = mergeTwoList(L1->next , L2);
        return L1;
    }
    else{
        //否则L2结点加入新链表
        L2->next = mergeTwoList(L1,L2->next);
        return L2;
    }
}
/*
 * 当 LA 和 LB 都不是空链表时，判断 LA 和 LB 哪一个链表的头结点的值更 小，
 * 将较小值的结点添加到结果里，
 * 当一个结点被添加到结果里之后，将对应链 表中的结点向后移一位。
 * 在循环终止的时候，只需要简单地将非空链表接在合并 链表的后面，并返回合并链表即可。
 */
ListNode *mergeTwoList2(List &L1 , List &L2){
    ListNode *p = new ListNode ;//创建一个头结点
    ListNode *s = p;//s指针做遍历
    while (L1 != NULL && L2 != NULL){
        if (L1->val < L2->val){
            s->next = L1;
            L1 = L1->next;
        }
        else{
            s->next = L2;
            L2 = L2->next;
        }
        s = s->next;
    }
    s->next = L1 == NULL ? L2 : L1;//将剩余结点连接
    //释放开始时创建的结点；
    ListNode *temp = p;
    p = p->next;
    //删除创建的头结点
    delete temp;
    //返回结果
    return p;
}
//打印链表
void printList(List &L){
    ListNode *p = L;
    if (p != NULL){
        cout<<p->val<<"  ";
        printList(p->next);
    }
}
int main(){
    List L1,L2,L3,L4;
    L1 = createList(0);//3 2 1 0
    L2 = createList(0);//6 5 4 0
    printList(L1);
    cout<<endl;
    printList(L2);
    cout<<endl;
    L3 = mergeTwoList(L1,L2);
    printList(L3);
    cout<<endl;
//    L4 = mergeTwoList2(L1,L2);


//    printList(L4);
//    cout<<endl;


}
