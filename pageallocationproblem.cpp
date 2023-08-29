#include<bits/stdc++.h>
using namespace std;
bool ispossible(int arr[],int mid,int n,int m){
    int sum=0 ,studentsrequired=1;
    for(int i=0;i<n;i++){
    if(arr[i] > mid){
        return false;
      }
      if(sum+arr[i] > mid){
        sum=arr[i];
        studentsrequired++;
        if(studentsrequired > m){
            return false;
        }
      }else{
          sum+=arr[i];
      }

    }
    return true;

}
int allocatepage(int arr[],int n,int m){
    if(n < m){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
    sum+=arr[i];
    }
    int start=0,end=sum,ans=INT_MAX;
    while(start <=end){
        int mid=(start+end)/2;
       if(ispossible(arr,mid,n,m)){
           ans=min(ans,mid);
           end=mid-1;
       }else{
           start=mid+1;
       }
    }
    return ans;
}
int main(){
    int arr[]={12,34,67,90};
    int n=4;
    int m=2;
    cout<<"the minimum no of pages: "<<allocatepage(arr,n,m);
    return 0;
}