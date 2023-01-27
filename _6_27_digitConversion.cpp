//
// Created by 徐朝阳 on 2022/6/27.
//

//将十进制N，转换成R进制。2<=R<=16
#include "iostream"
#include "stack"

using namespace std;
void conversion(int N ,int R){
    stack<int>(s);
    while (N){
        s.push(N%R);
        N=N/R;
    }
    while (!s.empty()){
        if (s.top()==10) cout<<"A";
        else if (s.top()==11) cout<<"B";
        else if (s.top()==12) cout<<"C";
        else if (s.top()==13) cout<<"D";
        else if (s.top()==14) cout<<"E";
        else if (s.top()==15) cout<<"F";
        else
            cout<<s.top();
        s.pop();
    }
    cout<<endl;
}
int main(){
    int N1=4,R1=2;
    int N2=78,R2=16;
    conversion(N1,R1);

    conversion(N2,R2);
}