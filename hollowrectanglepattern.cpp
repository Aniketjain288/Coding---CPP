#include<iostream>
using namespace std;
int main(){
    int col,row;
    cout<<"ENTER THE NUMBER OF ROWS"<<endl;
    cin>>row;
    cout<<"ENTER THE NUMBER OF columns"<<endl;
    cin>>col;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1||j==1||i==row||j==col){
                cout<<"*";
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
    }
    return 0;
}