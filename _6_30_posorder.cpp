//
// Created by 徐朝阳 on 2022/6/30.
//
//对树的后序遍历
#include "iostream"
#include "stack"
using namespace std;
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}TreeNode,*Tree;

//递归创建二叉树
TreeNode *createTree(Tree &t){
    char x;
    cin>>x;
    if(x=='#') return NULL;
    t=new TreeNode ;
    t->val=x;
    t->left= createTree(t->left);
    t->right= createTree(t->right);
    return t;
}

//递归后序遍历
void posOrder(Tree &t){
    if (t==NULL) return;
    posOrder(t->left);
    posOrder(t->right);
    cout<<t->val<<"  ";
}

//非递归后序遍历
/*
 * 与中序遍历差别在于从左孩子走到根节点后不是急着输出根节点，
 * 而是再进入右节点，之后再返回，这样根节点就会被访问两次，
 * 设置指向上一个被访问的结点的标志Pre，限制它只能访问一次右孩子
 */
void posOrderTraversal(Tree &t){
    stack<TreeNode*>(s);//建立一个存放树节点的栈
    TreeNode *p=t;
    TreeNode *pre=NULL;//标记已经访问过的结点
    while (p!=NULL||!s.empty()){
        //先一路向左
        while (p!=NULL){
            s.push(p);
            p=p->left;
        }
        p=s.top();//查看栈顶结点，准备操作栈顶结点
        //如果右孩子为空或者右孩子已经访问过，则访问这个根节点
        if (p->right==NULL || p->right==pre){
            cout<<p->val<<"  ";
            s.pop();//删除已经访问的栈顶结点
            pre=p;//记录已经访问
            p=NULL;//设为NULL避免再次入栈
        }
        //右孩子非空并且右孩子并未访问过。
        //转向右孩子执行上述过程
        else p=p->right;
    }

}
int main(){
    Tree t;
    t= createTree(t);
    posOrder(t);
    cout<<endl;
    posOrderTraversal(t);
}