//
// Created by 徐朝阳 on 2022/6/19.
//

//括号匹配
#include "iostream"
#include "stack"
using namespace std;

bool isValid(char *str){
    stack<char>(s);
    //边遍历字符串边匹配
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]=='('){
            s.push(')');
        }
        else if (str[i]=='['){
            s.push(']');
        }
        else if (str[i]=='{'){
            s.push('}');
        }
        //出现单独的右括号，或者左右括号不匹配
        else if (s.empty()||s.top()!=str[i]){
            return false;
        } else s.pop();//匹配成功，弹出。
    }
    return true;
}
int main(){
    char str[5]={'(','[',']',')'};
    cout<<isValid(str);

}