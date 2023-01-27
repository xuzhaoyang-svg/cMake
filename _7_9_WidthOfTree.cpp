//
// Created by 徐朝阳 on 2022/7/9.
//

//求二叉树的最大宽度，用递归和非递归两种方式
#include "iostream"
#include "queue"//层序遍历需要队列
using namespace std;

//递归创建二叉树
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
//非递归方式
int maxWidth(Tree &t){
    if (t==NULL) return 0;
    int max=0;
    queue<TreeNode*>(q);
    q.push(t);
    while (!q.empty()){
        int width=q.size();//本层宽度
        for (int i = 0; i < width; i++) {
            TreeNode *s=q.front();
            q.pop();
            if (s->left) q.push(s->left);
            if (s->right) q.push(s->right);

        }
        max=max > width ? max : width;
    }
    return max;
}
//递归方式
/*
 * 开辟一个数组count[二叉树高度],遍历每一个节点,然后根据当前节点所在层次i,则执行count[i]++
 * 最后遍历完求出最大的count即为二叉树宽度
 * 记录了每层结点数，比较
 */
int countW[100];//用于存每层的宽度
int width=-1;
void getWidth(Tree &t,int k){
    if (t==NULL) return;
    countW[k]++;
    width = width > countW[k] ? width : countW[k];
    getWidth(t->left,k+1);
    getWidth(t->right,k+1);

}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    getWidth(t,0);
    cout<<width<<"递归"<<endl;
    cout<<maxWidth(t)<<"非递归"<<endl;

}