#include<iostream>
using namespace std;

void alphabetornot(char a){
    if((a>='A'&&a<='Z')||(a>='a'&&a<='z')){
        cout<<a<<" is alphabet";
    }else{
        cout<<a<<" is not an alphabet";
    }
    return;
}
int main(){
    char c;
    cin>>c;
    alphabetornot(c);
    return 0 ;

}
