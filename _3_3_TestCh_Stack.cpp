//
// Created by 徐朝阳 on 2023/3/3.
//

#include "iostream"
#include "ch_stack.h"
// 在编译文件上加入源文件
using namespace std;
int main(){
    char str[50] = {"An idle youth, a needy age."};
    cout << str << endl;
    ch_stack s; // 实例化对象s
    s.clear();
    int i = 0;
    // str不为空且栈s不为满
    while (str[i] && !s.full()){
        s.push(str[i++]);
    }
    while (!s.empty()){
        cout << s.pop();
    }
    cout << endl;
}