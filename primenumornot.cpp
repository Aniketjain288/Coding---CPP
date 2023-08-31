#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int i;
    for(int i=2;i<n;i++){
        if(i%2==0){
            cout<<"NOT A PRIME NUMBER"<<endl;
            break;
        }
    }if(i==n){
        cout<<"prime number"<<endl;
    }
    return 0;
}