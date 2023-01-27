//
// Created by 徐朝阳 on 2022/7/8.
//

//求二叉树的高度，用递归和非递归两种方法
#include "iostream"
#include "queue"
#include "stack"
using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}TreeNode,*Tree;

//递归生成二叉树
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

//递归走到树的最底层，再通过比较左右子树的高度，取较高一颗+1，一直累加到树根
/*
 * 求树的高度可以分解为求树的子树的高度再加1，子树的高度同样等于子树的子树的高度加1，
 * 这样就可以一层一层的向下分解，直到最后一层叶子节点，它没有左右子树了，这时它的高度是1，
 * 这也就是递归终止条件，然后向上返回树的高度。
 * 当树只有左子树或者右子树时，直接求对应子树的高度即可，
 * 如果左右子树都存在的话，就需要判断左子树和右子树哪个高，返回更高的数值。
 */
int Height(Tree &t){
    if (t==NULL) return 0;//当前结点为空返回0
    return Height(t->left)> Height(t->right) ? Height(t->left)+1: Height(t->right)+1;
}
//改编层次遍历，又根向下每遍历一层，深度+1
int Depth(Tree &t){
    if (t==NULL)  return 0;
    queue<TreeNode*>(q);
    q.push(t);
    int depth=0;
    while (!q.empty()){
        int n=q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *s=q.front();
            q.pop();
            if (s->left) q.push(s->left);
            if (s->right) q.push(s->right);
        }
        depth+=1;
    }
    return depth;
}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    cout<<Height(t)<<"递归"<<endl;
    cout<<Depth(t)<<"非递归"<<endl;

}