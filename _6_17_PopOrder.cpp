//
// Created by 徐朝阳 on 2022/6/17.
//

//判断是否是正确的出栈序列。例入栈：1，2，3。出栈：3，2，1。
#include "iostream"
#include "stack"
#include "queue"
using namespace std;

bool popOrder(int *pop,int *push ,int l){
    //队列存储出栈顺序
    queue<int>(q);
    for(int i=0;i<l;i++){
        q.push(pop[i]);
    }
    //栈存储入栈序列
    stack<int>(s);
    for (int i = 0; i < l; i++) {
        s.push(push[i]);
    }
    //判断是否是正确的出栈序列
    while (!s.empty()&&s.top()==q.front()){
        //s非空并且栈顶元素=对头元素
        s.pop();
        q.pop();
    }
    if (!s.empty()){
        return false;//S非空则不正确
    }
    return true;
}
int main(){
    int pop[5]={1,2,3,4,5},push[5]={5,4,3,2,1};
    int r= popOrder(pop,push,5);
    cout<<r;

}