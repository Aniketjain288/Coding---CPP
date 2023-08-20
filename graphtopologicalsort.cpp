#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj(n);
    vector<int> ind(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        //x->y
        adj[x].push_back(y);
        ind[y]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(ind[i] == 0){
        pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int node=pq.front();
        pq.pop();
        cout<<node<<" ";
        for(auto j:adj[node]){
            ind[j]--;
            if(ind[j] == 0){
                pq.push(j);
            }
        }
    }
    if(cnt!=0){
        cout<<"The given graph is not cyclic";
    }else{
        cout<<"The given graph is cyclic"<<endl;
    }
    return 0;
}