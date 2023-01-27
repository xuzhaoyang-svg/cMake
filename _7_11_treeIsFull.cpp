//
// Created by 徐朝阳 on 2022/7/11.
//

//判断一颗二叉树是不是满二叉树，用递归和非递归方式
#include "iostream"
#include "queue"
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

//非递归
bool levelOrder(Tree &t){
    if (t==NULL) return true;//空树也是满二叉树
    queue<TreeNode*>(q);
    int num=1;//控制每层结点个数
    q.push(t);
    while (!q.empty()){
        int width=q.size();
        for (int i = 0; i < width; i++) {
            TreeNode *s=q.front();
            q.pop();
            if (s->left) q.push(s->left);
            if (s->right) q.push(s->right);

        }
        if (width<num) return false;
        else num*=2;
    }
    return true;
}

//递归
//求树高度
int Height(Tree &t){
    if (t==NULL) return 0;
    return Height(t->left) > Height(t->right) ? Height(t->left)+1 : Height(t->right)+1;
}
//判断满二叉树
bool isFull(Tree &t){
    if (t==NULL) return true;
    return isFull(t->left) && isFull(t->right) && Height(t->left) == Height(t->right);
}

int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #

    cout<<"非递归： "<<levelOrder(t)<<endl;
    cout<<"递归： "<<isFull(t)<<endl;

}