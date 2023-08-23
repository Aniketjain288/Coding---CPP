#include<bits/stdc++.h>
using namespace std;
int maxarea(vector<int> a){
    int n=a.size(),i=0,ans=0;
    stack<int> st;
    while(i<n){
        while(!st.empty() && a[st.top()] > a[i]){
            int h =a[st.top()];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }else{
                int len=i-st.top()-1;
                ans=max(ans,len*h);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
int main(){
    vector<int> a={2,1,5,6,2,3};
    cout<<maxarea(a)<<endl;
    return 0;
}