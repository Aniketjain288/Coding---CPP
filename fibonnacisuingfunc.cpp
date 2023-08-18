#include<iostream>
using namespace std;

void fib(int num){
    int a=0;
    int b=1;
    cout<<a<<"\n"<<b<<endl;
    for(int i=3;i<=num;i++){
        int sum=a+b;
        cout<<sum<<endl;
        a=b;
        b=sum;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    fib(n);
    return 0;
}
