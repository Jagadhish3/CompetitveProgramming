#include <iostream>
#include <stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

void enque(int ele) {
    stack1.push(ele);
}

int deque1() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (stack2.empty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    int front = stack2.top();
    stack2.pop();
    return front;
}

int peek() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (stack2.empty()) {
        cout << "Queue is empty." << endl;
        return -1; // or some error code
    }
    return stack2.top();
}

int main() {
    enque(1);
    enque(2);
    enque(3);

    cout << "Front element: " << peek() << endl; // Should print 1
    int x =  deque1();
    cout << "Dequeued: " <<x<< endl;    // Should print 1
    cout << "Front element after dequeue: " << peek() << endl; // Should print 2
    cout << "Dequeued: " << deque1() << endl;    // Should print 2
    cout << "Dequeued: " << deque1() << endl;    // Should print 3

    // Attempting to dequeue from an empty queue
    cout << "Dequeued from empty queue: " << deque1() << endl; // Should print "Queue is empty."

    return 0;
}
