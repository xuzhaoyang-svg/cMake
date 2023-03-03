//
// Created by 徐朝阳 on 2023/3/3.
//

#include "ch_stack.h"
#include "cassert"

const int EMPTY = -1;
// 参数初始化
// 构造函数重载多个
ch_stack::ch_stack(int size) : top(EMPTY), max_len(size){
    assert(size > 0);
    s = new char[size];
}
ch_stack::ch_stack() : ch_stack(100){}
ch_stack::ch_stack(const char str[], int size) : max_len(size){
    assert(size > 0);
    s = new char[size];
    int i;
    for (i = 0; i < max_len && str[i] != 0; ++i){
        s[i] = str[i];
    }
    top = --i;
}
ch_stack::~ch_stack() {
    delete []s;
}
void ch_stack::clear() {
    top = EMPTY;
}
void ch_stack::push(char c) {
    s[++top] = c;
}
char ch_stack::pop() {
    return s[top--];
}
char ch_stack::top_of() {
    return s[top];
}
bool ch_stack::empty() {
    return top == EMPTY;
}
bool ch_stack::full() {
    return top == max_len -1;
}
int ch_stack::size() {
    return top + 1;
}



