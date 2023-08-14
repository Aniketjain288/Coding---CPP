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
void insertionathead(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertionattail(node* &head,int val){
   if(head==NULL){
       insertionathead(head,val);
       return;
   }
   node* n=new node(val);
   node* temp=head;
   while(temp->next!=head){
       temp=temp->next;
   }
   temp->next=n;
   n->next=head;

}
void deletionathead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete=head;
    head=head->next;
    temp->next=head;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deletionathead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(count!=pos-1){
      temp=temp->next;
      count++;
    }
    node* todelete =temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;

}
int main(){
    node *head=NULL;
    insertionattail(head,1);
    insertionattail(head,2);
    insertionattail(head,3);
    insertionattail(head,4);
    insertionattail(head,5);
    insertionattail(head,6);
    display(head);
    insertionathead(head,7);
    display(head);
    // deletionathead(head);
    deletion(head,3);
    display(head);
    return 0;
}
