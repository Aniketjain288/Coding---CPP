#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int j;
        int k=i;
        for(j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(;j<=n;j++){
            cout<<k<<" ";
            k--;
        }
        k=2;
        for(;j<n+i;j++){
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
    return 0;
}