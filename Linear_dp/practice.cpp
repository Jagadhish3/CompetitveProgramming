#include<bits/stdc++.h>
using namespace std;
/*
//Array rotation
void rev(int arr[],int k,int n){
    while(k<n){
        swap(arr[k],arr[n]);
        k++;
        n--;
    }
}

int main(){
    int n = 8;
    int arr[n] = {1,2,3,4,5,6,7,8};
    int k = 3;
    rev(arr,0,n-1);
    rev(arr,0,k-1);
    rev(arr,k,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
*/
/*
//lower triangular matrix
int main(){
    int m=3;
    int n=3;
    int arr[m][n] = {{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                cout<<"  ";
            }else{
                cout<<arr[i][j]<<" ";
            }
            
        }
        cout<<endl;
    }
}
*/
/*
//Upper triangular matrix
int main(){
    int m=3;
    int n=3;
    int arr[m][n] = {{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(i<=j){
               cout<<arr[i][j]<<" ";
            }else{
                cout<<"  ";
                continue;
            }
            
        }
        cout<<endl;
    }
}
*/
/*
//spiral form of a matrix
int main(){
    int m = 3;
    int n = 4;
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int top = 0;
    int bottom = m-1;
    int left = 0;
    int right = n-1;
    int res[m*n];
    int index = 0;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res[index] = arr[top][i];
            index++;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res[index] = arr[i][right];
            index++;
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            res[index] = arr[bottom][i];
            index++;
        }
        bottom--;
        }
        if(left<=bottom){
        for(int i=bottom;i>=top;i--){
            res[index] = arr[i][left];
            index++;
        }
        left++;
        }
    }
    for(int i=0;i<m*n;i++){
        cout<<res[i]<<" ";
    }
}
*/
/*
//different uniqe elements in each row of a matrix
int main(){
    int m=3;
    int n=4;
    int arr[m][n] = {{1,2,1,3},{1,1,3,4},{3,5,1,1}};

    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[0][i]]++;
    }

    for(int i=1;i<m;i++){
        unordered_map<int,int> row;
        for(int j=0;j<n;j++){
            int ele = arr[i][j];

            if(freq.find(ele)!=freq.end()){
                row[ele]++;
            }
        }
        for(auto &f:freq){
            f.second = min(f.second, row[f.first]);
        }
        

    }
    bool f = false;
    for(auto p:freq){
        while(p.second-- > 0){
            cout<<p.first<<" ";
            f = true;
        }
    }
    if(!f){
        cout<<"No elements";
    }
}
*/
/*
//anagram
int main(){
    string s1 = "Listen";
    string s2 = "silent";

    int arr[26] = {};

    for(char c:s1){
        c = tolower(c);
        arr[c-'a']++;
    }

    for(char c:s2){
        c = tolower(c);
        arr[c-'a']--;
    }

    // bool res = true;
    int count = 0;
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
           count++;
        }
    }

    cout<<count;
}
*/
/*
//Pangram
int main(){
    string s = "The quick dog jumps over the brown fox";

    int arr[26] = {};
    for(char ch : s){
        ch = tolower(ch);
        arr[ch-'a']++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]==0){
            cout<<char(i+'a')<<" ";
        }
    }
}
*/
/*
//stack using linked list
struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

struct Stack{
    Node* top;

    Stack(){
        top = nullptr;
    }
    bool isempty(){
        return top==nullptr;
    }

    void push(int val){
        Node* newnode = new Node(val);
        newnode->next = top;
        top = newnode;
        cout<<val<<" is pushed"<<endl;
    }

    int pop(){
        if(isempty()){
            cout<<"Under flow";
            return -1;
        }

        Node* temp = top;
        top = top->next;
        int x = temp->data;
        delete temp;
        return x;
    }

    int peek(){
        if(isempty()){
            cout<<"Under flow";
            return -1;
        }

        return top->data;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int x = s.pop();
    cout<<x<<" is popped"<<endl;
    int y = s.peek();
    cout<<y<<" is peek element";
}
*/
/*
struct Node {
    int data;      // Data part of the node
    Node* next;    // Pointer to the next node
    Node* prev;    // Pointer to the previous node

    // Constructor to initialize the node
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Define the structure for the Doubly Linked List
struct DoublyLinkedList {
    Node* head;    // Pointer to the head of the list
    Node* mid;     // Pointer to the middle of the list
    int count;     // Count of nodes in the list

    // Constructor to initialize the doubly linked list
    DoublyLinkedList() : head(nullptr), mid(nullptr), count(0) {}

    // Function to push a new element to the front of the list
    void push(int val) {
        Node* newnode = new Node(val);
        if (head == nullptr) {
            head = newnode;
            mid = newnode;  // Initialize mid to the first node
        } else {
            newnode->next = head;  // Set the new node's next to current head
            head->prev = newnode;   // Set current head's prev to new node
            head = newnode;         // Move head to point to the new node
        }
        count++;

        // Update mid
        if (count == 1) {
            mid = newnode;  // If it's the first element, set mid to new node
        } else if (count % 2 == 0) {
            mid = mid->prev;  // Move mid left when count is even
        } else {
            mid = mid->next;  // Move mid right when count is odd
        }
    }

    // Function to pop the front element from the list
    void pop() {
        if (head == nullptr) {
            cout << "Underflow\n";
            return;
        }

        Node* temp = head; // Store the current head node
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr; // Update the new head's previous pointer
        } else {
            mid = nullptr; // If the list becomes empty, set mid to nullptr
        }

        cout << "Popped element: " << temp->data << endl;
        delete temp; // Delete the old head node
        count--;

        // Update mid
        if (count % 2 == 1) { // Move mid to the right when count is odd
            mid = (mid != nullptr) ? mid->next : nullptr;
        } else if (count > 0) { // Move mid to the left when count is even
            mid = (mid != nullptr) ? mid->prev : nullptr;
        }
    }

    // Function to get the middle element in O(1) time
    int getMiddle() {
        if (mid == nullptr) {
            return -1; // Return -1 if mid is nullptr
        }
        return mid->data;
    }

    // Function to print the list in forward direction
    void print() {
        Node* curr = head;
        cout << "List in forward direction: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            pop();
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // Example for inserting elements and displaying the middle element
    int n, value;
    cout << "How many elements do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        dll.push(value);
        cout << "Current middle element: " << dll.getMiddle() << endl; // Display current mid after each insertion
    }

    dll.print(); // Print the entire list at the end

    return 0;
}
*/

struct node{
    int data;
    node* next;

    node(int val){
        data=val;
        next=nullptr;
    }
}*head = nullptr;

node* push(int ele){
    node *newnode = new node(ele);

    if(head==nullptr){
        head=newnode;
        return newnode;
    }else{
        node *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return newnode;
}

void display(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

node* remove(node* head,int n){

    node* temp=new node(-1);
    temp->next=head;
    node* slow=temp;
    node* fast=temp;
    int c=0;
    while(c<=n){
        fast=fast->next;
        c++;
    }

    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;
    return temp->next;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    remove(head,2);
    display(head);
}

