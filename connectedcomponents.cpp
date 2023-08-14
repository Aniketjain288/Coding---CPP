#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> components;
int n,m;
int get_components(int idx){
    if(vis[idx]){
        return 0;
    }
    int ans=1;
    vis[idx]=true;
    for(auto i:adj[idx]){
     if(!vis[i]){
      ans+=get_components(i);
      vis[i]=true;
    }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
      if(!vis[i]){
          components.push_back(get_components(i));
      }
    }
      for(auto i:components){
          cout<<i<<" ";
      }
      cout<<endl;
      //friends problem
      long long ans=0;
      for(auto i:components){
          ans+=i*(n-i);
      }
      cout<<(ans/2)<<endl;
      return 0;
}