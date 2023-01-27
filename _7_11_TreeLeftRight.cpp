//
// Created by 徐朝阳 on 2022/7/11.
//

//判断一棵树是不是完全二叉树
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
/*
 * 由于完全二叉树在每一层非空节点都是一个接一个连续分布的，不可能出现两个非空节点之间交叉一个空节点，因此：
    我们可以通过层序遍历从上往下，从左往右将每一个节点（包括空节点）都放到队列里
    在出队列的过程中，如果遇到空节点，则跳出循环
    跳出循环后，然后再判断队列中剩下的元素是否有非空节点：
                有非空节点：非完全二叉树；
                没有非空节点（全是空节点）：完全二叉树。
 */
bool levelOrder(Tree &t){
    if (t==NULL) return true;
    queue<TreeNode*>(q);
    q.push(t);
    while (!q.empty()){
        TreeNode *s =  q.front();
        q.pop();
        if (s!=NULL){
            q.push(s->left);//为空就入队NULL
            q.push(s->right);
        }
        else//S为空检查队中还有无非空结点
            while(!q.empty()){
                s=q.front();
                q.pop();
                if(s!=NULL)//有非空结点返回False
                    return false;
            }
    }
    return true;
}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    cout<<"完全二叉树递归： "<<levelOrder(t)<<endl;
}