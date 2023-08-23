#include<bits/stdc++.h>
using namespace std;
vector<int>[] prevsmaller(int a[]){
    int ps[]=new int[a.length()];
    stack s;
    for(int i=0;i<a.length();i++){
        while(!s.empty() && a[s.top[]] >= a[i]){
            s.pop();
        }
        if(s.empty()){
            ps[i]=-1;
        }else{
          ps[i]=s.top();
        }
        s.push(i);
    }
    return ps;
}
vector<int>[] nextsmaller(int a[]){
    int ns[]=new int[a.length()];
    stack s;
    for(int i=a.length();i>0;i--){
        while(!s.empty() && a[s.top[]] >= a[i]){
            s.pop();
        }
        if(s.empty()){
            ps[i]=-1;
        }else{
          ns[i]=s.top();
        }
        s.push(i);
    }
    return ns;
}
int maxarea(int a[]){
    int maxans=0;
    int ps[]=prevsmaller(a);
    int ns[]=nextsmaller(a);
    for(int i=0;i<a.length();i++){
        int cur=(ns[i]-ps[i]-1)*a[i];
        maxans=max(maxans,cur);
    }
    return maxans;
}
int main(){
    int a[]={4,2,1,5,6,3,2,4,2};
    cout<<maxarea(a);
    return 0;
}