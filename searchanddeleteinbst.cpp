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
Node* searchbts(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchbts(root->left,key);
    }
    return searchbts(root->right,key);
}
Node* inordersucc(Node* root){
    Node* curr=root;
    while(curr && curr->left !=NULL){
        curr=curr->left;
    }
    return curr; 

}
Node* deletebts(Node* root,int key){
    if(root->data > key){
        root->left=deletebts(root->left,key);
    }else if(root->data < key){
        root->right=deletebts(root->right,key);
    }else{
        if(root->left == NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deletebts(root->right,temp->data);
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
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    // Node* ans=searchbts(root,10);
    // if(ans == NULL){
    //     cout<<"key does not exist"<<endl;
    // }else{
    //     cout<<"key exist"<<endl;
    // }
    inorder(root);
    cout<<endl;
    root = deletebts(root,5);
    inorder(root);
    return 0;
}