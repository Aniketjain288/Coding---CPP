#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;
void color(int idx,int curr){
    if(col[idx] != -1 && col[idx] != curr){
        bipart=false;
        return;
    }
    if(vis[idx]){
        return;
    }
    col[idx]=curr;
    vis[idx]=true;
    for(auto i:adj[idx]){
        color(i,curr xor 1);
        //0 xor 1=1
        //1 xor 1=0
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,0);
    col=vector<int>(n,-1);
    bipart=true;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            color(i,0);
        }
    }
    if(bipart){
        cout<<"Graph is bipartite"<<endl;
    }else{
        cout<<"Graph is not bipartite"<<endl;
    }
    return 0;
}