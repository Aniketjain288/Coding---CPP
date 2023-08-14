#include<iostream>
using namespace std;

int counthpath(int s,int e){
   if(s==e){
       return 1;
   }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count+=counthpath(s+i,e);
    }
    return count;

}
int main(){
    cout<<counthpath(0,3);
    return 0;
}