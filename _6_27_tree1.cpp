//
// Created by 徐朝阳 on 2022/6/27.
//

//以先序遍历递归的构造一棵二叉树
#include "iostream"
#include "queue"
using namespace std;
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}BiTNode,*BiTree;

node * createTree(BiTree &t){
    char x;//char类型存储的是整数而不是字符。例如ASCII 65代表A
    cin>>x;
    if (x=='#') return NULL;//遇到'#'为空结点
    t=new BiTNode ;//否则创建一个新结点
    t->val=x;
    t->left= createTree(t->left);//递归创建左子树
    t->right= createTree(t->right);//递归创建右子树
    return t;
}
//按层输出层序遍历
void levelOrder(BiTree &t){
    if (t==NULL) return;
    queue<BiTNode*>(q);//层序遍历使用队列
    q.push(t);
    while (!q.empty()){
        int n=q.size();//首先，根结点入队队size=1。然后根节点两个子结点入队…………
        for (int i = 0; i < n; i++) {//输出一层
            BiTNode *s=q.front();
            cout<<s->val<<" ";
            q.pop();//弹出队头元素
            if (s->left) q.push(s->left);
            if (s->right) q.push(s->right);
        }
        cout<<endl;//换行
    }

}
int main(){
    BiTree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    levelOrder(t);
}