
//Finding minimum element from stack in BigO(1) using one stack
#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
int mini = INT_MAX;
void push1(int ele){

    s1.push(mini);
    if(ele<mini){
        mini = ele;
    }
    s1.push(ele);
    
}

void pop1(){

   
    if(mini==s1.top()){
        s1.pop();
        mini = s1.top();
        s1.pop();
    }else{
        s1.pop();
    
    }
   
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