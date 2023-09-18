#include<iostream>
using namespace std;
void swap(int n1,int n2){
    int temp =n1;
    n1=n2;
    n2=temp;
    cout<<"after swapping "<<n1<<"  "<<n2;
    return;
}
    int main(){
        int a,b;
        cin>>a>>b;
        swap(a,b);
        return 0;
    }