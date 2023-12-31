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
Node* insertbst(Node* root,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left=insertbst(root->left,val);
    }else{
        root->right=insertbst(root->right,val);
    }
    return root;
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=NULL;
    root=insertbst(root,5);
    insertbst(root,1);
    insertbst(root,3);
    insertbst(root,4);
    insertbst(root,2);
    insertbst(root,7);
    inorder(root);
    cout<<endl;
    return 0;
}