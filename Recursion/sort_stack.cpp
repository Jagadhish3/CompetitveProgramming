#include<iostream>
using namespace std;

int top = -1;
#define n 100
int stack1[n];
bool isEmpty(){
   return top==-1;
}

bool isFull(){
    return top>n-1;
}

void push(int num){
   if(isFull()){
    cout<<"Stack overflow";
    return;
   }
    stack1[++top] = num;
    }
int pop(){
    if(isEmpty()){
        cout<<"stack is empty";
        return -1;
    }
    return stack1[top--];
}

int peek(){
     if(isEmpty()){
        cout<<"stack is empty";
        return -1;
    }
    return stack1[top];
}

void insertSorted(int ele){
    if(isEmpty() || peek()<=ele){
        push(ele);
        return;
    }

    int temp = pop();
    insertSorted(ele);
    push(temp);
}

void sortStack(){
    if(isEmpty()){
        return;
    }

    int temp = pop();
    sortStack();
    insertSorted(temp);
}

void display(){
    if(isEmpty()){
        cout<<"Stack is empty";
        return;
    }

    for(int i=top;i>=0;i--){
        cout<<stack1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    push(18);
    push(12);
    push(67);
    push(5);
    push(32);
    sortStack();
    display();

}

#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, item);
    
    st.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    
    int topElement = st.top();
    st.pop();
    
    // Reverse the remaining stack
    reverseStack(st);
    
    // Insert the removed element at the bottom
    insertAtBottom(st, topElement);
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    
    // Sample stack elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    cout << "Original Stack: ";
    printStack(st);
    
    reverseStack(st);
    
    cout << "Reversed Stack: ";
    printStack(st);
    
    return 0;
}