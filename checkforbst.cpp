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
bool isbst(Node* root,Node* min,Node* max){
    if(root == NULL){
        return true;
    }
    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }
    int leftvalid=isbst(root->left,min,root);
    int rightvalid=isbst(root->right,root,max);
    return leftvalid and rightvalid;
}
int main(){
    Node* root1=new Node(5);
    root1->left=new Node(8);
    root1->right=new Node(3);
    if(isbst(root1,NULL,NULL)){
        cout<<"binary tree exist"<<endl;
    }else{
        cout<<"binary tree does not exist"<<endl;
    }
    Node* root2=new Node(2);
    root2->left=new Node(1);
    root2->right=new Node(3);
    if(isbst(root2,NULL,NULL)){
        cout<<"binary tree exist"<<endl;
    }else{
        cout<<"binary tree does not exist"<<endl;
    }
    return 0;

}