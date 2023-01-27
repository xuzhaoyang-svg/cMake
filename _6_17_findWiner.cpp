//
// Created by 徐朝阳 on 2022/6/17.
//

#include "iostream"
#include "queue"
using namespace std;

/*
 * 使用队列解决约瑟夫环问题
 * n个玩家，每轮从1开始报数到K淘汰第K个玩家，剩余到最后一个玩家获胜。
*/
int findTheWinner(int n ,int k ){
    queue<int>(q);
    //初始化游戏
    for (int i = 1; i < n; i++) {
        q.push(i);
    }
    while (--n){
        //如果剩一个玩家就返回这个玩家编号
        if (n==1){
            return q.front();
        }
        //每轮前K-1个玩家再次入局。
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();//淘汰第K个玩家。

    }
    return 0;
}
int main(){
    int n=10,k=3;
    int e= findTheWinner(3,2);
    cout<<"TheWinner: "<<e;
}