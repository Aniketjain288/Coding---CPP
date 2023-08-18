#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"0\n";
    }else if(n==2){
        cout<<"0 1\n";
    }else{
        int sum,i=3,a=0,b=1;
        cout<<a<<" \n"<<b<<" \n";
        while(i<=n){
            sum=a+b;
            cout<<sum<<" \n";
            a=b;
            b=sum;
            i++;
        }
    }
    return 0;
}