#include<iostream>
using namespace std;
string removdup(string s){
    if(s.length()==0){
        return "";
    }
    char ch =s[0];
    string ans=removdup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);

}
int main(){
    cout<<removdup("aaafffhhyuuagg");
    return 0;
}
