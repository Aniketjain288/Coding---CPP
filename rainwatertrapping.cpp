#include<bits/stdc++.h>
using namespace std;
int rainwater(vector<int> a){
    stack<int> s;
    int ans=0;
    for(int i=0;i<a.size();i++){
        while(!s.empty() && a[s.top()]< a[i]){
            int cur=s.top();
            s.pop();
            if(s.empty()){
                break;
            }
            int diff =i-s.top()-1;
            ans+=(min(a[s.top()],a[i])-a[cur])* diff;
        }
        s.push(i);
    }
    return ans;
}
int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rainwater(a);
    return 0;
}