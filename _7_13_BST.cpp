//
// Created by 徐朝阳 on 2022/7/13.
//

//判断一棵树是不是二叉搜索树，使用递归和非递归。二叉搜索树的特点是中序遍历递增。
#include "iostream"
#include "stack"
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

//非递归 参考中序遍历 左< 根 < 右。最小值一定在左下角
bool IsValidBST(Tree &t){
    stack<TreeNode*>(s);
    int pre=INT_MIN;//pre保存当前结点中序遍历前驱值
    TreeNode *p=t;
    while (!s.empty()||p!=NULL){
        while (p!=NULL){
            s.push(p);
            p=p->left;
        }
        p=s.top();
        s.pop();
        if (p->val<=pre) return false;
        pre=p->val;
        p=p->right;
    }
    return true;
}

//递归
int last=INT_MIN;
bool isValidBST(Tree &t){
    if (t==NULL) return true;
    if (isValidBST(t->left)){//检查左子树，在左子树是二叉搜索树的基础上，运行下列代码
        if (last<t->val){//比较当前节点，并更新已遍历节点最后的值
            last=t->val;
            return isValidBST(t->right);//检查右子树
        }
    }
    return false;//左子树,有任意一处不符合规则，返回false
}

/*方法二、省掉线性空间，保存遍历的最后一个节点*/
int lastVal = INT_MIN;
bool checkBST2(Tree &root) {
    // write code here
    if (!root)
        return true;

    /*递归检查左子树*/
    if (!checkBST2(root->left))
        return false;

    /*比较当前节点，并更新已遍历节点最后的值*/
    if (root->val <= lastVal)
        return false;
    lastVal = root->val;

    /*递归检查右子树*/
    if (!checkBST2(root->right))
        return false;
    return true;
}


int main(){
    Tree t;
    t= createTree(t);//B C # # C # #
    cout<<"递归1： "<<isValidBST(t)<<endl;
    cout<<"递归2： "<<checkBST2(t)<<endl;
    cout<<"非递归： "<<IsValidBST(t)<<endl;
}