//
// Created by 徐朝阳 on 2022/6/13.
//

#include "iostream"
#include "stack"
using namespace std;

/*数组传入函数有三种方式
 * (1)f(int *s); (2)f(int s[]); (3)f(int s[size])。 s是形参，与主函数定义的名字可以不相同
 */
//使用栈判断回文字符串
bool isPalindrome(char str[]){
    stack< char > s ;
    for (int i = 0; i < strlen(str); i++) {
        s.push(str[i]);
    }
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]==s.top()){
            s.pop();
        } else{
            return false;
        }
    }
    return true;
}

int main(){
    char str1[5];
    str1[0]='a',str1[1]='b',str1[2]='a';
    cout<<isPalindrome(str1)<<endl;
}