#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }

}*head=nullptr,*temp=nullptr;


void push(int ele){
    node* newnode = new node(ele);
    if(head==nullptr){
        head = newnode;
        temp = newnode;
    }
    else{
        temp->next = newnode;
        temp=newnode;
    }
}

void display(){
    node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
void createCycle(int pos) {
    if (head == nullptr || pos <= 0) return;
    
    node* cycleNode = head;
    node* lastNode = head;
    int currentPos = 1;

    // Traverse to the node at the given position
    while (cycleNode != nullptr && currentPos < pos) {
        cycleNode = cycleNode->next;
        currentPos++;
    }
    
    // If the position is out of bounds, return without creating a cycle
    if (cycleNode == nullptr) return;

    // Find the last node
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    
    // Create a cycle by pointing the last node's next to the cycleNode
    lastNode->next = cycleNode;
}

node* checkcycle(){
    bool hascycle = false;
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            hascycle=true;
            break;
        }
    }
    if(hascycle==false){
        return nullptr;
    }

    return slow;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display(); 

    createCycle(4);

    node* cycleNode = checkcycle();
    if(cycleNode == nullptr){
        cout << "No cycle in the linked list." << endl;
    } else {
        cout << "Cycle detected!" << endl;
    }

    return 0;
}