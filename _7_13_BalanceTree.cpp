//
// Created by 徐朝阳 on 2022/7/13.
//
//判断一颗二叉树是否是二叉平衡树，左子树与右子树高度差绝对值不大于1，先求高度，在判断平衡
#include "iostream"
#include "stdlib.h"
using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}TreeNode,*Tree;

TreeNode *createTree(Tree &t){
    char x;
    cin>>x;
    if (x=='#') return NULL;
    t=new TreeNode ;
    t->val=x;
    t->left= createTree(t->left);
    t->right= createTree(t->right);
    return t;
}
//递归求二叉树高度
int Height(Tree &t){
    if (t==NULL) return 0;
    return Height(t->left) > Height(t->right) ? Height(t->left) + 1 : Height(t->right) +1;
}
bool isBalance(Tree &t){
    if (t==NULL) return true;
    return abs(Height(t->left) - Height(t->right))<=1 && isBalance(t->left) && isBalance(t->right);
}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    cout<<"递归： "<<isBalance(t)<<endl;
}