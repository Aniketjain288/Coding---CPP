#include<bits/stdc++.h>
using namespace std;
bool pairsum(int arr[],int n,int k){
    int low=0;
    int high =n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }else if(arr[low]+arr[high]>k){
            high--;
        }else{
            low++;
        }
    }
 return false;
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int k=31;
    // int arr[]={2,4,7,11,14,16,20,21};
    cout<<pairsum(arr,n,k)<<endl;
    return 0;
}