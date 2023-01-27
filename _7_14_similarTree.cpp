//
// Created by 徐朝阳 on 2022/7/14.
//

//判断两棵二叉树是否相似
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

/*
 * 递归方法
 * 两颗二叉树在结构上相同，则认为它们是相似的。
 * 即在相同位置都为空，或者都不为空。
 */
bool isSimilarTree(Tree &t1,Tree &t2){
    if (t1==NULL&&t2==NULL) return true;
    if (!(t1&&t2)) return false;//有一处不同返回false
    return isSimilarTree(t1->left,t2->left) && isSimilarTree(t1->right,t2->right);
}
int main(){
    Tree t1,t2;
    t1= createTree(t1);//B C # # C # #
    t2= createTree(t2);//B C # # #
    cout<<"是否相似： "<<isSimilarTree(t1,t2)<<endl;
}