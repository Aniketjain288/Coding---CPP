#include<bits/stdc++.h>
using namespace std;
int isfeasible(int arr[],int mid,int n){
    int painters=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum > mid){
            sum=arr[i];
            painters++;
        }
    }
    return painters;
}
int painterpartition(int arr[],int n,int m){
    int totallength=0,k=0;
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
        totallength+=arr[i];
    }
    int low=k,high=totallength;
    while(low < high){
        int mid=(low+high)/2;
        int painters =isfeasible(arr,mid,n);
        if(painters <=m){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int arr[]={10,20,30,40};
    int n=4;
    int m=2;
    cout<<"Minimum to paint boards : "<<painterpartition(arr,n,m);
    return 0;
}