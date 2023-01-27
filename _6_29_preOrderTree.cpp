//
// Created by 徐朝阳 on 2022/6/29.
//
//先序遍历使用栈
#include "iostream"
#include "stack"
using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}TreeNode,*Tree;

//递归创建一棵树
TreeNode * createTree(Tree &t){
    char x;
    cin>>x;
    if (x=='#') return NULL;//返回空，跳出这层递归，返回上一层。
    t=new TreeNode ;//创建一个新结点
    t->val=x;
    t->left= createTree(t->left);
    t->right= createTree(t->right);
    return t;
}
//递归方法先序遍历
void preOrder(Tree &t){
    if (t==NULL) return;//空返回
    cout<<t->val<<"  ";//访问
    preOrder(t->left);//遍历左子树
    preOrder(t->right);//遍历右子树
}

//非递归方法先序遍历Traversal专有词汇
void preOrderTraversal(Tree &t){
    if (t==NULL) return;//空树返回NULL
    stack<TreeNode*> (s);//创建一个TreeNode类型的栈
    s.push(t);
    while (!s.empty()){//栈非空一直运行
        TreeNode *p=s.top();
        s.pop();
        cout<<p->val<<"  ";

        if (p->right) s.push(p->right);//右子树入栈
        if (p->left) s.push(p->left);//左子树入栈
    }
}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    preOrder(t);
    cout<<endl;
    preOrderTraversal(t);
}