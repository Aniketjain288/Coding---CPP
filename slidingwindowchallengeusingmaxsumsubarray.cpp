#include<bits/stdc++.h>
using namespace std;
void maxsumsubarray(int arr[],int n,int k,int x){
    int sum=0,ans=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum < x){
        ans = sum;
    }
    for(int i=k;i<n;i++){
        sum=sum-arr[i-k];
        sum=sum+arr[i];
       if(sum < x){
        ans = max(sum,ans);
       }
    }
    cout<<ans<<" is the max sum subarray"<<endl;
}
int main(){
    int arr[]={7,5,4,6,8,9};
    int x=20;
    int k=3;
    int n=6;
    maxsumsubarray(arr,n,k,x);
    return 0;  
}