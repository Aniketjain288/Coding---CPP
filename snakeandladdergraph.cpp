#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> lad;
    map<int,int> snak;
    int snake,ladder;
    cin>>ladder;
    for(int i=0;i<ladder;i++){
        int u,v;
        cin>>u>>v;
        lad[u]=v;
    }
    cin>>snake;
    for(int i=0;i<snake;i++){
        int u,v;
        cin>>u>>v;
        snak[u]=v;
    }
    queue<int> q;
    int moves=0;
    vector<bool> vis(101,0);
    bool found=false;
    q.push(1);
    vis[1]=true;
    while(!q.empty() and !found){
        int sz=q.size();
        while(sz--){
            int t=q.front();
            q.pop();
            for(int dice=1;dice<=6;dice++){
              if(t + dice == 100){
                  found=true;
              }
              if(t+dice <= 100 and lad[t+dice] and !vis[lad[t+dice]]){
                  vis[lad[t+dice]]=true;
                  if(t+dice == 100){
                      found = true;
                  }
                  q.push(lad[t+dice]);
              }else if(t+dice <= 100 and snak[t+dice] and !vis[snak[t+dice]]){
                      vis[snak[t+dice]]=true;
                      if(t+dice == 100){
                        found = true;
                      }
                    q.push(snak[t+dice]);
            }else if(t+dice <= 100 and !snak[t+dice] and !lad[t+dice] and !vis[t+dice]){
                      vis[t+dice]=true;
                      if(t+dice == 100){
                        found = true;
                      }
                    q.push(t+dice);
             }
            }
        }
        moves++;
    }
    if(found){
        cout<<moves<<endl;
    }else{
        cout<<"-1"<<endl;
    }
    return 0;
}