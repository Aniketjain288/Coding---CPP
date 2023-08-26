#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
node* middlenode(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    head=slow;
    return slow;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
void insertattail(node* &head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp =head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        insertattail(head,arr[i]);
    }
    middlenode(head);
    display(head);
    return 0;
}