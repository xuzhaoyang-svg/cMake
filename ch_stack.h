//
// Created by 徐朝阳 on 2023/3/3.
//

#ifndef CMAKE_CH_STACK_H
#define CMAKE_CH_STACK_H


class ch_stack{
public:
    ch_stack(); // 构造默认构造函数
    explicit ch_stack(int size); // 指定栈的大小
    ch_stack(const char str[], int size); // 用字符串初始化栈
    ~ch_stack(); // 析构函数
    void clear(); // 清空栈
    void push(char c); // 压栈
    char pop(); // 出栈
    char top_of(); // 返回栈顶元素
    bool empty(); // 栈是否为空
    bool full(); // 栈是否满
    int capacity(); // 返回栈的最大容量
    int size(); // 栈中元素个数
private:
    char *s = nullptr; // 栈元素存储空间
    int top; // 栈顶指示器
    int max_len; // 栈最大长度

};
#endif //CMAKE_CH_STACK_H
