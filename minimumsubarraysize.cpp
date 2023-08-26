#include<bits/stdc++.h>
using namespace std;
int minimumsubarraysize(int arr[],int n,int x){
    int start=0,end=0,minlength=n+1,sum=0;
    while(end < n){
        while(sum <= x && end < n){
            sum+=arr[end++];
        }
        while(sum > x && start < n){
            if(end - start < minlength){
                minlength=end-start;
            }
            sum-=arr[start++];
        }
    }
    return minlength;
}
int main(){
    int arr[]={1,4,45,6,10,19};
    int n=6;
    int x=51;
    int ans=minimumsubarraysize(arr,n,x);
    if(ans == n+1){
        cout<<"no subarray exists"<<endl;
    }else{
        cout<<"minimumsubarray size is "<<ans<<endl;
    }
    return 0;
}