#include<iostream>
using namespace std;

int sumtilln(int n){
    if(n==0){
        return 0;
    }
    return n+sumtilln(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<sumtilln(n)<<endl;
    return 0;
}