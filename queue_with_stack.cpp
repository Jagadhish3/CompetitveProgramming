#include<iostream>
using namespace std;
#include<stack>
stack<int> stack1;
stack<int> stack2;
void enque(int ele){
    stack1.push(ele);
}
int deque(){
    while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
    }
    int front = stack2.top();
    stack2.pop();
    return front;
}
int peek(){
    while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
    }
    int front = stack2.top();
    return front;
}

int main(){
    
}