#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;

    node(int val){
        data=val;
        next=nullptr;
    }
};
void print(node* head){
    node* curr = head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

}
void insertBegin(node*& head,int ele){
    node* curr = new node(ele);
    curr->next=head;
    head=curr;
}
void insertAtpos(node*& head,int ele,int pos){
    node* newnode = new node(ele);
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    node* temp = head;
    for(int i=1;i<=pos-2;i++){
        if(temp==nullptr){
            cout<<"out of range";
            return;
        }
        temp=temp->next;
    }
    if(temp!=nullptr){
        newnode->next = temp->next;
        temp->next=newnode;
    }else{
        cout<<"out of range";
    }
}
void insertEnd(node*& head,int ele){
    node* temp = new node(ele);
    if(head==nullptr){
        head=temp;
        return;
    }
    node* curr = head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=temp;
}
int main(){
    node* head = nullptr;
    node* temp = nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        node* newnode = new node(ele);

        if(head==nullptr){
            head=newnode;
        }else{
            temp->next=newnode;
        }
       temp= newnode;
    }
    // print(head);
    int e,pos;
    cin>>e>>pos;
    // insertBegin(head,e);
    // insertEnd(head,e);
    insertAtpos(head,e,pos);
    print(head);
}
