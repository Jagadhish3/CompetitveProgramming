
//Finding minimum element from stack in BigO(1) using Two stacks
#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s2;
int mini = INT_MAX;
void push1(int ele){

    s1.push(ele);
    if(ele<mini){
        mini = ele;
    }
    s2.push(mini);
        
}

void pop1(){

    if(s1.empty()){
        return;
    }
    
    s1.pop();
    s2.pop();
    mini = s2.top();

}

int min(){
    return mini;
}


int main(){
    push1(10);
    push1(5);
    push1(12);
    push1(2);
    push1(1);
    cout<<min()<<endl;
    pop1();
    pop1();
    cout<<min()<<endl;
    

}