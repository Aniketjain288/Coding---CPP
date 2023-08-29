#include<iostream>
using namespace std;

bool primeoreven(int num){
    for(int i=2;i<num;i++){
        if(num%i==0){
           return false;
        }
    }
 return true;
}
int main(){
    int n;
    cin>>n;
    if(primeoreven(n)==true){
        cout<<n<<"is prime number";
    }else{
        cout<<n<<"is non-prime number";
    }
    return 0;
}