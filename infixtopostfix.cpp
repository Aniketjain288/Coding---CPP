#include<iostream>
#include<stack>
using namespace std;

int pre(char c){
    if(c=='^'){
        return 3;
    }else if(c=='/' || c=='*'){
        return 2;
    }else if(c=='-' || c=='+'){
        return 1;
    }else{
        return -1;
    }
}
string infixtopostfix(string s){
    stack<char> st;
    string res;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
            res+=st.top();
            st.pop();
            }
            if(!st.empty()){
            st.pop();
            }
        }
        else{
            while(!st.empty() && pre(st.top())>=pre(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;

}
int main(){
    cout<<infixtopostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
  
}
// #include<iostream>
// #include <string>
// #include <stack>
// using namespace std;

// //Function to check the precedence of operators
// int precedence(char c)
// {
//     if (c == '^')
//         return 3;
//     else if (c == '/' || c == '*')
//         return 2;
//     else if (c == '-' || c == '+')
//         return 1;
//     else
//         return -1; //for paranthesis
// }

// //Function to convert infix to postfix
// string InfixToPostfix(string exp)
// {
//     stack<char> s;
//     string res;
//     for (int i = 0; i < exp.size(); i++)
//     {
//         if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z')
//             res = res + exp[i];
//         else if (exp[i] == '(')
//             s.push(exp[i]);
//         else if (exp[i] == ')')
//         {
//             while (s.top() != '(')
//             {
//                 res = res + s.top();
//                 s.pop();
//             }
//             s.pop();
//         }
//         else
//         {
//             while (!s.empty() && precedence(s.top()) >= precedence(exp[i]))
//             {
//                 res = res + s.top();
//                 s.pop();
//             }
//             s.push(exp[i]);
//         }
//     }
//     while (!s.empty())
//     {
//         res = res + s.top();
//         s.pop();
//     }
//     return res;
// }

// int main()
// {
//     cout << InfixToPostfix("(a-b/c)*(a/k-l)") << endl;
// }