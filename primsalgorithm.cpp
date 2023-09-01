#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
const int INF=1e9;
int n,m;
int cost=0;
vector<vector<int>> g[N];
vector<int> parent(N),dist(N);
vector<bool> vis(N);
void prims(int source){
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[source]=0;
    set<vector<int>> s;
    s.insert({0,source});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1];
        int v=parent[x[1]];
        int w=x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto it:g[x[1]]){
            if(vis[it[0]]){
                continue;
            }
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]]=it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]]=x[1];
            }
        }
    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    prims(0);
    cout<<cost<<endl;
}