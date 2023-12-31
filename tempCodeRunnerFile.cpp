#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    sz[v]=1;
}
int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b){
     a=find_set(a);
     b=find_set(b);
 if(a != b){
    if(sz[a] < sz[b])
       swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];  
 }
}
int32_t main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edge;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edge.push_back({w,x,y});
    }
    sort(edge.begin(),edge.end());
    int cost = 0;
    for(auto i:edge){
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int a = find_set(u);
        int b = find_set(v);
        if(a == b){
           continue;
        }else{
            cost += w;
            cout<<u<<" "<<v<<endl;
            union_sets(u,v);
        }
    }
    cout<<cost<<endl;
    return 0;
}