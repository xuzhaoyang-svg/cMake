//
// Created by 徐朝阳 on 2023/2/26.
//

#include "iostream"

using namespace std;
const int NumberOfPrimes = 50; // 前50个素数
const int NumberPreLine = 10; // 每行显示10个

int main(){
    int count = 0; // 素数个数计数器
    int number = 2; // 要测试的数
    cout << "前50个素数是：" << endl;
    while (count < NumberOfPrimes){
        // 检测number是否是素数
        bool isPrime = true;
        // 3开始才进入for循环，2不符合条件
        for (int i = 2; i <= number/2; ++i) {
            if (number % i == 0){
                isPrime = false;
                break;
            }
        }
        // number是素数，count增加，输出
        if (isPrime){
            ++count;
            // 一行素数满足10个，换行
            if (count % NumberPreLine == 0){
                cout << number << "\n";
            } else{
                // 不足10个
                cout << number << " ";
            }
        }
        ++number; // 下一个数；
    }
}
