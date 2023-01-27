//
// Created by 徐朝阳 on 2022/8/16.
//
#include "iostream"

using namespace std;
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}TreeNode,*Tree;

TreeNode *createTree(Tree  &t){
    char x;
    cin >> x;
    if (x == '#') return NULL;
    t = new TreeNode ;
    t->val = x;
    t->left = createTree(t->left);
    t->right = createTree(t->right);
    return t;
}
void printTree(Tree &t){
    if (t == NULL) return;
    printTree(t->left);
    printTree(t->right);
    cout<< t->val<<" ";

}
TreeNode *posOrderFirstNodeVal(Tree &t){
    TreeNode *p = t;
    if (p != NULL){
        while (p->left != NULL || p->right != NULL){
            while (p->left != NULL) p = p->left;
            if (p->right != NULL) p = p->right;
        }
        return p;
    }

}
int main(){
    Tree t;
    TreeNode *p;
    createTree(t);//A B D # # E # # C F # # G # #
    printTree(t);
    cout<<endl;
    p = posOrderFirstNodeVal(t);
    cout<<p->val;
}
