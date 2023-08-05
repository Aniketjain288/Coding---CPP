#include<iostream>
using namespace std;

int getbit(int n,int pos){
    return ((n &(1<<pos))!=0);
}
int setbit(int n,int pos){
    return(n |(1<<pos));
}
int clearbit(int n,int pos){
    int mask= ~(1<<pos);
    return (n & mask);
}
int toggle(int n,int pos){
    return(n xor (1<<pos) );
}
int updatebit(int n,int pos,int value){
    int mask= ~(1<<pos);
    n= (n & mask);
    return(n |(value<<pos));
}
int main(){
      int n,pos,value;
    //   cout<<getbit(5,0);
    // cout<<setbit(5,1)<<endl;
    // cout<<clearbit(5,2);
    // cout<<toggle(5,1);
    cout<<updatebit(5,1,1);
      return 0;

}