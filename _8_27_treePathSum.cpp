//
// Created by 徐朝阳 on 2022/8/27.
//
//求取一棵二叉树的路径长度（指从树根到树所有结点的路径长度之和，二叉树中结点的路径长度为该结点所在层次值-1，根节点为第一层；）
//方法一：改编层序遍历
//方法二：使用递归，每往下走一层，路径长度+1；
//层序遍历二叉树使用队列
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
    if(x=='#') return NULL;
    t=new TreeNode ;
    t->val=x;
    t->left= createTree(t->left);
    t->right= createTree(t->right);
    return t;
}

//层序遍历
void levelOrder(Tree &t){
    if (t==NULL) return;
    queue<TreeNode*>(q);
    q.push(t);
    int layer=0;
    int pathSum = 0;
    while (!q.empty()){
        int n=q.size();
        pathSum += layer * n;
        layer++;
        for (int i = 0; i < n; i++) {
            TreeNode *s=q.front();//栈就是TreeNode *p=s.top()
            cout<<"第"<<layer<<"层："<<s->val<<"  ";
            q.pop();
            //将左右孩子入队
            if (s->left) q.push(s->left);
            if (s->right) q.push(s->right);

        }
        cout<<endl;
    }
    cout<<"pathSum:"<<pathSum<<endl;
}
int main(){
    Tree t;
    cout<<"please input:";
    t= createTree(t);//A B D # # E # # C F # # G # #
    levelOrder(t);
}