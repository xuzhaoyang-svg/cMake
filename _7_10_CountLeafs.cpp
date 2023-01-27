//
// Created by 徐朝阳 on 2022/7/10.
//

//求二叉树的叶子结点数，使用递归和非递归两种方式
#include "iostream"
#include "queue"
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

//非递归方式：改编层序遍历。由根向下广度优先遍历，每遍历一个结点判断一次
int leafs(Tree &t){
    if (t==NULL) return 0;
    int count=0;//统计叶子结点数
    queue<TreeNode*>(q);
    q.push(t);
    while (!q.empty()){
        TreeNode *s=q.front();
        if (s->left==NULL&&s->right==NULL)//判断是不是叶子结点
            count++;
        q.pop();
        if (s->left) q.push(s->left);
        if (s->right) q.push(s->right);

    }
    return count;
}
//递归：由上至下寻找叶子结点，遍历到最底部逐层往上汇报
int Count(Tree &t){
    if (t==NULL) return 0;
    else if (t->left==NULL&&t->right==NULL)
        return 1;
    return Count(t->left)+ Count(t->right);
}

int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    cout<<"递归： "<<Count(t)<<endl;
    cout<<"非递归： "<<leafs(t)<<endl;
}

