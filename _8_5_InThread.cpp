//
// Created by 徐朝阳 on 2022/8/5.
//
//后序线索二叉树
#include "iostream"
using namespace std;

typedef struct node{
    char val;
    struct node *left,*right;
    int ltag=0,rtag=0;
}TreeNode,*Tree;

//后序线索化
void InThread(Tree &t,TreeNode *&pre){
    //pre指针指向t的后序前驱，在主函数中预设为NULL
    if (t != NULL){
        InThread(t->left,pre);//左子树线索化
        InThread(t->right,pre);//右子树线索化
        if(t->left == NULL){
            //建立当前结点的前序线索
            t->left = pre;
            t->ltag = 1;
        }
        if (pre->right == NULL && pre){
            //建立前驱结点pre的后继线索
            pre->right = t;
            pre->rtag = 1;
        }
        pre = t;//前驱跟上当前结点
    }
}
//建立后序线索二叉树
void CreateThread(Tree &t){
    TreeNode *pre = NULL;//前驱指针
    if (t != NULL) InThread(t,pre);
}

