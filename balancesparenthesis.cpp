#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }else{
                return false;
                break;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }else{
                return false;
                break;
            }
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }else{
                return false;
                break;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
}
int main(){
    string s="{[()]}";
    if(isvalid(s)){
        cout<<"string is valid"<<endl;
    }else{
        cout<<"string is not valid"<<endl;
    }
    return 0;
}