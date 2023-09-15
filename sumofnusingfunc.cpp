#include<iostream>
using namespace std;

int sumofn(int n){
    return (n*(n+1))/2;
}
int main(){
    int n;
    cin>>n;
    cout<<sumofn(n)<<endl;
    return 0;
}
