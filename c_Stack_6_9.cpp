//
// Created by 徐朝阳 on 2022/6/9.
//

#include "iostream"
#include "stack"
#include "queue"
using namespace std;
int main(){
    stack<int>(S);
    int x=1,y;
    cout<<"isEmpty:"<<S.empty()<<endl;//1为空，0为非空

    S.push(x);
    y=S.top();
    S.pop();
    cout<<y<<endl;
    cout<<"isEmpty:"<<S.empty()<<endl;
}