//
// Created by 徐朝阳 on 2022/7/14.
//

//交换二叉树的左右子树
/*我们在交换二叉树的左右子树时用递归来实现。
 * 可以从根开始交换二 叉树的左右子树，然后再分别交换左右子树各自的左右子树，也就是用前序遍历 的顺序从上到下来交换;
 * 也可以是先交换树的边缘部分的左右子树，一直从下往上来交换，直至交换了根的左右子树，也就是通过后序遍历的顺序实现从下到上的交换。
 */
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

//从上至下交换二叉树，前序遍历
void swapByPreOrder(Tree &t){
    if (t==NULL) return;//返回上一层
    TreeNode *p=t->left;
    t->left=t->right;
    t->right=p;
    swapByPreOrder(t->left);
    swapByPreOrder(t->right);
}

//从下至上交换二叉树，后序遍历
void swapByPostOrder(Tree &t){
    if (t==NULL) return;//返回上一层
    swapByPostOrder(t->left);
    swapByPostOrder(t->right);
    TreeNode *p=t->left;
    t->left=t->right;
    t->right=p;
}
//层序遍历
void levelOrder(Tree &t){
    if (t==NULL) return;
    queue<TreeNode*>(q);
    q.push(t);
    while (!q.empty()){
        int size=q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *s=q.front();
            q.pop();
            cout<<" "<<s->val;
            if (s->left) q.push(s->left);
            if (s->right) q.push(s->right);
        }
        cout<<endl;
    }
}
int main(){
    Tree t;
    t= createTree(t);//A B D # # E # # C F # # G # #
    cout<<"没交换交换左右子树"<<endl;
    levelOrder(t);
    cout<<"第一次交换左右子树"<<endl;
    swapByPreOrder(t);
    levelOrder(t);
    cout<<"第二次交换左右子树"<<endl;
    swapByPostOrder(t);
    levelOrder(t);
}