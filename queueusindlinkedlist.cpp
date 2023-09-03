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
class queue{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n=new node(x);
        if(front==NULL){
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;

    }
    void pop(){
        if(front==NULL){
            cout<<"no elements in queue"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek(){
        if(front==NULL){
            cout<<"no elements in queue"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
};
int main(){
    queue s;
     s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}
