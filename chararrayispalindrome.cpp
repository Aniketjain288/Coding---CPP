#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char a[n];
    cin>>a;
    bool check=1;
    for(int i=0;i<n;i++){
        if(a[i] != a[n-1-i]){
        check=0;
        break;
    }
    }
    if(check){
        cout<<a<<" is a palindrome"<<endl;
    }else{
        cout<<a<<" is not a palindrome"<<endl;
    }
    return 0;
}