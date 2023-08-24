#include<iostream>
using namespace std;

void max(int n1,int n2,int n3){
    if(n1>n2){
        if(n1>n3){
            cout<<"max="<<n1<<endl;
        }else{
            cout<<"max="<<n3<<endl;
        }
    }else if(n2>n3){
        cout<<"max="<<n2<<endl;
    }else{
        cout<<"max="<<n3<<endl;
    }
    return;
}

void min(int n1,int n2,int n3){
    if(n1<n2){
        if(n1<n3){
            cout<<"min="<<n1<<endl;
        }else{
            cout<<"min="<<n3<<endl;
        }
    }else if(n2<n3){
        cout<<"min="<<n2<<endl;
    }else{
        cout<<"min="<<n3<<endl;
    }
    return;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    max(a,b,c);
    min(a,b,c);
    return 0;
}