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