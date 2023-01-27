//
// Created by 徐朝阳 on 2022/7/10.
//

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
//非递归：广度优先遍历，逐个计数
int AllLeafs(Tree &t){
    if (t==NULL) return 0;
    queue<TreeNode*>(q);
    q.push(t);
    int conutleafs=0;
    while (!q.empty()){
        TreeNode *s=q.front();
        conutleafs++;
        q.pop();
        if (s->left) q.push(s->left);
        if (s->right) q.push(s->right);
    }
    return conutleafs;
}

//递归：递归到树的最底部，返回左右子树的结点数再+1，表示左右子树再加上父节点

int ConntLeafs(Tree &t){
    if (t==NULL) return 0;
    return ConntLeafs(t->left)+ ConntLeafs(t->right)+1;
}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    cout<<"递归： "<<ConntLeafs(t)<<endl;
    cout<<"非递归： "<<AllLeafs(t)<<endl;
}