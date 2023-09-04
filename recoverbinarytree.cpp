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
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void calacpointers(Node* root,Node** first,Node** last,Node** mid,Node** prev){
    if(root == NULL){
        return;
    }
    calacpointers(root->left,first,last,mid,prev);
    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *mid=root;
            *first=*prev;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    calacpointers(root->right,first,last,mid,prev);
}
void restorebst(Node* root){
    Node* first,*last,*mid,*prev;
    first=NULL;
    last=NULL;
    mid=NULL;
    prev=NULL;
    calacpointers(root,&first,&last,&mid,&prev);

    if(first && last){
        swap(&(first->data),&(last->data));
    }else if(first && mid){
        swap(&(first->data),&(mid->data));
    }
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
     Node* root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->right=new Node(13);
    inorder(root);
    cout<<endl;
    restorebst(root);
    inorder(root);
    cout<<endl;
    return 0;

}