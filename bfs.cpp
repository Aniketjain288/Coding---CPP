#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> adj[N];
bool vis[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<N;i++){
        vis[i]=0;
    }
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
    return 0;
}