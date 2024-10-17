#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data=val;
        next=nullptr;
    }
}*headA=NULL,*headB=NULL;


node* addnode(int data){
    node* newnode = new node(data);
    return newnode;
}
int count(node* head)
{
    node* curr = head;
    int c=0;
    while(curr!=nullptr){
        c++;
        curr=curr->next;
    }
    return c;
}
node* find_intersection(node* headA,node* headB){
        int m = count(headA);
        int n = count(headB);
        node* tempA = headA;
        node* tempB = headB;
        if(m>n){
            int x = m-n;
            while(x--){
                tempA=tempA->next;
            }
        }else if(n>m){
            int x = n-m;
            while(x--){
                tempB=tempB->next;
            }
        }

        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
    return tempA;

}

int main(){
    headA = addnode(1);
    headA->next=addnode(2);
    headA->next->next=addnode(3);

    headB=addnode(20);
    headB->next=addnode(30);
    headB->next->next=headA->next;


    node* intersection = find_intersection(headA, headB);
    if (intersection) {
        cout << "Intersection elements are: " << endl;
        while(intersection!=nullptr){
            cout<<intersection->data<<" ";
            intersection=intersection->next;
        }
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
