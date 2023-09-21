#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    bool found=false;
    for(int i=0;i<n;i++){
        int lo=i+1,hi=n-1;
        while(lo<hi){
            int current=a[i]+a[lo]+a[hi];
        if(current == target){
           found=true;
           cout<<a[i]<<" "<<a[lo]<<" "<<a[hi];
        } if(current < target){
          lo++;
        }else{
            hi--;
        }
        }
    }
    if(found==true){
       cout<<"target is found"<<endl;
    }else{
        cout<<"target is not found"<<endl;
    }
  return 0;
}