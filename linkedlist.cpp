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
void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
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
bool searching(node* head,int key){
   node* temp=head;
   while(temp!=NULL){
   if(temp->data==key){
     return true;
   }
   temp=temp->next;
}
return false;
}
void deleteathead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
       deleteathead(head);
       return;
    }

    node* temp=head;
    if(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
node* reverse(node* &head){
    node* currptr=head;
    node* prevptr=NULL;
    node* nxtptr;
    while(currptr!=NULL){
        nxtptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nxtptr;
    }
    return prevptr;
}
node* reversereccurr(node* &head){
    if(head==NULL|| head->next==NULL){
        return head;
        }
        node* newnode=reversereccurr(head->next);
        head->next->next=head;
        head->next=NULL;
        return newnode;
}
node* reversek(node* &head,int k){
    node* currptr=head;
    node* nxtptr;
    node* prevptr=NULL;
    int count=0;
    while(currptr!=NULL && count<k){
        nxtptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nxtptr;
        count++;
    } 
    if(nxtptr!=NULL){
    head->next=reversek(nxtptr,k);
    }
    return prevptr;
}
void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
         startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}
bool detectioncycle(node* &head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void removecycle(node* head){
     node* fast=head;
     node* slow=head;
     do{
         slow=slow->next;
         fast=fast->next->next;
     }while(slow!=fast);
     fast=head;
     while(fast->next != slow->next){
         fast=fast->next;
         slow=slow->next;
     }
     slow->next=NULL;
}
int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
node* kappend(node* &head,int k){
     int l=length(head);
     k=k%l;
     node* newhead;
     node* newtail;
     node* tail=head;
     int count=1;
     while(tail->next!=NULL){
         if(count==l-k){
             newtail=tail;
         }
         if(count==l-k+1){
             newhead=tail;
         }
         tail=tail->next;
         count++;
     }
     newtail->next=NULL;
     tail->next=head;
     return newhead;
}
node* removeNthFromEnd(node* &head, int n) {
        int l=length(head);
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
    node* head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    // makecycle(head,3);
    // cout<<detectioncycle(head)<<endl;
    // display(head);
    // removecycle(head);
    display(head);
    // node* newhead=kappend(head,3);
    // display(newhead);
    removeNthFromEnd(head,1);
    display(head);
    

    
    // display(head);
    // // cout<<searching(head,4);
    // deletion(head,3);
    // display(head);
    // deleteathead(head);
    // display(head);
    // node* newnode=reversereccurr(head);
    // display(newnode);
    // node* newnode=reversek(head,2);
    // display(newnode);
    

    return 0;
}