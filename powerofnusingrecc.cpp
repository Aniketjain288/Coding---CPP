#include<iostream>
using namespace std;

int powerofn(int n, int p){
    if(p==0){
        return 1;
    }
    return n*powerofn(n,p-1);
}
int main(){
    int n,p;
    cin>>n>>p;
    cout<<powerofn(n,p)<<endl;
    return 0;

}