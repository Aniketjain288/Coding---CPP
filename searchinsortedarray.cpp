#include<bits/stdc++.h>
using namespace std;
int searchinsortedarray(int arr[],int key,int left,int right){
    if(left > right){
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid] == key){
        return  mid;
    }
    if(arr[left] <= arr[mid]){
        if(arr[left] <= key && key <= arr[mid]){
            return searchinsortedarray(arr,key,left,mid-1);
        }
        return searchinsortedarray(arr,key,mid+1,right);
    }
    if(arr[right] >= key && arr[mid] <= key){
        return searchinsortedarray(arr,key,mid+1,right);
    }
    return searchinsortedarray(arr,key,left,mid-1);
}
int main(){
    int arr[]={6,7,8,9,10,1,2,5};
    int key=8;
    int n=8;
    int idx=searchinsortedarray(arr,key,0,n-1);
    if(idx == -1){
        cout<<"No key found"<<endl;
    }else{
        cout<<"key is present at idx: "<<idx<<endl;
    }
    return 0;
}