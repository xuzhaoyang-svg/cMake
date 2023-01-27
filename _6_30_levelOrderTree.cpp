//
// Created by 徐朝阳 on 2022/6/30.
//

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
    while (!q.empty()){
        int n=q.size();

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
}
int main(){
    Tree t;
    cout<<"please input:";
    t= createTree(t);//A B D # # E # # C F # # G # #
    levelOrder(t);
}