//
// Created by 徐朝阳 on 2022/7/14.
//
//判断两颗二叉树是否相同，在相似的基础上加上对val的判断
#include "iostream"
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
    if (x=='#') return NULL;
    t=new TreeNode ;
    t->val=x;
    t->left= createTree(t->left);
    t->right= createTree(t->right);
    return t;
}

bool isSameTree(Tree &t1,Tree &t2){
    if (t1==NULL && t2==NULL) return true;
    if (!(t1 && t2 && t1->val==t2->val)) return false;
    return isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right);
}

int main(){
    Tree t1,t2;
    t1= createTree(t1);//B C # # C # #
    t2= createTree(t2);//B C # # #
    cout<<"是否相同： "<<isSameTree(t1,t2)<<endl;
}