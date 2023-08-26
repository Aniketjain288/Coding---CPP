#include<iostream>
using namespace std;

string movx(string s){
    if(s.length()==0){
        return "";
    }
   char ch=s[0];
   string ans=movx(s.substr(1));
   if(ch=='x'){
       return ans+ch;
   }
   return ch+ans;
}
int main(){
    cout<<movx("axxbdxxjhixx");
    return 0;
}