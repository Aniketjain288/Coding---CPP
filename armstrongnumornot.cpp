#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0,orgnum = n;
    while(n>0){
        int rem=n%10;
        sum=sum+rem*rem*rem;
        n/=10;
    }
    if(sum==orgnum){
        cout<<"arsmtrongnumber";
    }else{
        cout<<"not armstrongnumber";
    }
    return 0;
    }