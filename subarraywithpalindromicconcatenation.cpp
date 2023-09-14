#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(int n){
    int temp=n;int num=0;
    while(temp > 0){
        num=num*10+temp%10;
        temp=temp/10;
    }
    if(num == n){
        return true;
    }
    return false;
}
int palindromicsubarray(vector<int> arr,int k){
    int num=0;
    for(int i=0;i<k;i++){
        num=num*10+arr[i];
    }
    if(ispalindrome(num)){
        return 0;
    }
    for(int j=k;j,arr.size();j++){
        num=(num %(int)pow(10,k-1))*10+arr[j];
        if(ispalindrome(num)){
            return j-k+1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr={2,3,5,1,4,5};
    int k=4;
    int ans=palindromicsubarray(arr,k);
    if(ans == -1){
        cout<<"No palindromic sunarray exists"<<endl;
    }else{
        for(int i=ans;i<ans+k;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}