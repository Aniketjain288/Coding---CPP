#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    char opr;
    cout<<"enter two number:"<<endl;
    cin>>n1>>n2;
    cout<<"enter operation:"<<endl;
    cin>>opr;
    switch (opr)
    {
    case '+':
    cout<<"addition of two numbers:"<<n1+n2<<endl;
        break;
    case '-':
    cout<<"subtraction of two numbers:"<<n1-n2<<endl;
        break;
    case '*':
    cout<<"multiplication of two numbers:"<<n1*n2<<endl;
        break;
    case '/':
    cout<<"division of two numbers:"<<n1/n2<<endl;
        break;

    default:
    cout<<"no operation found"<<endl;
        break;
    }
    return 0;
}