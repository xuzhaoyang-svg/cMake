//
// Created by 徐朝阳 on 2022/7/20.
//
//判断一个字符串是不是回文串
/*1用双指针，一个 left 指向第一个字符，一个 right 指向最后一个 字符，将两个指针所指的字符进行对比，
 * 如若相同向中心继续进行上述比较，如若不同则不是回文串
 */
/*
 * 2用递归，思想与双指针相同，递归的边界条件是当 left 等于 right(奇数字 符串)或者 left 大于 right(偶数字符串)结束，
 * 当 left 与 right 所指字符不 相同就不是回文串。
 */
/*
 * 3用栈，将字符串整个压入栈中，再从栈中拿出字符与原字符串的第一个字符开 始两两作比较，如若出现不匹配则不是回文串。
 */
#include "iostream"
#include "stack"
using namespace std;
//双指针
bool isPalindrome(char *s){
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    while (left < right){
        if (s[left] != s[right]){
            return false;//不是回文串
        } else{
            left++;
            right--;
        }
    }
    return true;//是回文串
}
//递归
bool isPalindrome2(char *s , int left ,int right){
    //递归边界条件
    if (left == right || left > right) return true;
    else
        return s[left] == s[right] ? isPalindrome2(s, left +1 ,right - 1) : false;
}
//使用栈
bool isPalindrome3(char *s){
    stack<int>(st);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        st.push(s[i]);//全部字符进栈
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == st.top()) st.pop();
        else
            return false;
    }
    return true;
}

int main(){
    char str[] ="abc";
    char *s=str;
    cout << isPalindrome(s) << endl;
    cout<<isPalindrome2(s,0,2)<<endl;
    cout<<isPalindrome3(s);
}