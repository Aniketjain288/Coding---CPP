#include<bits/stdc++.h>
using namespace std;
struct  Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
        }
};
int countnodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
int sumofallnodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumofallnodes(root->left)+sumofallnodes(root->right)+root->data;
}
int calcheight(Node* root){
    if(root== NULL){
        return 0;
    }
    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);
    return max(lheight,rheight)+1;
}
int calcdaimeter(Node* root,int* height){
    if(root ==NULL){
        *height=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int lhdiameter=calcdaimeter(root->left,&lh);
    int rhdiameter=calcdaimeter(root->right,&rh);
    int currdiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currdiameter,max(lhdiameter,rhdiameter));
    }
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<countnodes(root)<<endl;
    cout<<sumofallnodes(root)<<endl;
    cout<<calcheight(root)<<endl;
    int height=0;
    cout<<calcdaimeter(root,&height)<<endl;
    return 0;
}
