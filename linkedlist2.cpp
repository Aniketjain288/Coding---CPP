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
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int length(node* head){
    node* temp=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    node* ptr1;
    node* ptr2;
    int d=0;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d=0){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next !=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
node* merge(node* &head1,node* &head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummynode=new node(-1);
    node* ptr3=dummynode;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummynode->next;
    
}
node* mergerecc(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
      return head1;
    }
    if(head1->data>head2->data){
        result=head2;
        result->next=mergerecc(head1,head2->next);
    }else{
        result=head1;
        result->next=mergerecc(head1->next,head2);
    }
    return result;
}
node* removeNthFromEnd(node* head, int n) {
        int l=lenght(head);
        int k=l-n;
        int count=1;
        node* temp=head;
        while(count<k){
            temp=temp->next;
            count++;
        }
        node* todelete =temp->next;
        temp->next=temp->next->next;
        delete todelete;
        return head;
    }
int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertattail(head1,3);
    insertattail(head1,5);
    insertattail(head1,6);
    insertattail(head1,8);
    insertattail(head1,9);
    insertattail(head1,10);
    insertattail(head2,4);
    insertattail(head2,7);
    // intersect(head1,head2,3);
    // display(head1);
    // display(head2);
    // cout<<intersection(head1,head2)<<endl;
    node* newnode=mergerecc(head1,head2);
    node* newnode=mergerecc(head1,head2);
    display(newnode);

    return 0;
}