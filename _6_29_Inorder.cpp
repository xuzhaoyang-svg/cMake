//
// Created by 徐朝阳 on 2022/6/29.
//

//Inorder是一个单词，meaning is 中序遍历
#include "iostream"
#include "stack"
using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}TreeNode,*Tree;

//递归创建一棵树
TreeNode *createTree(Tree &t){
    char x;//存储数据
    cin>>x;
    if (x=='#') return NULL;//#返回空跳出这层递归调用，返回上一层递归
    t=new TreeNode ;
    t->val=x;
    //创建左子树
    t->left= createTree(t->left);
    //创建右子树
    t->right= createTree(t->right);
    return t;
}

//递归中序遍历
void Inorder(Tree &t){
    if (t==NULL) return;
    Inorder(t->left);//递归遍历左子树
    cout<<t->val<<"  ";
    Inorder(t->right);//递归遍历右子树
}

//非递归中序遍历
void InorderTraversal(Tree &t){
    stack<TreeNode*>(s);
    TreeNode *p=t;
    while (p!=NULL || !s.empty()){
        //一路向左
        while (p!=NULL){
            s.push(p);
            p=p->left;
        }
        //左路已经走到头
        //出栈栈顶结点，最左下角结点
        p=s.top();
        s.pop();
        cout<<p->val<<"  ";
        //走向右孩子
        p=p->right;

    }

}

int main(){
    Tree t;
    t= createTree(t);
    Inorder(t);
    cout<<endl;
    InorderTraversal(t);
}