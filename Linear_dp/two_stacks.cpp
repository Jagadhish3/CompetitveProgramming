#include<iostream>
using namespace std;
// #include<stack>
int stack[5];
int top1;
int top2,n;
void push1(int ele){
    //code for two stacks  first starting from 0 and other from n/2

    // if(top1==n/2){
    //     return;
    // }

    //code for two stacks  first starting from 0 and other from n(from last)

    if(top1>top2){
        return;
    }
    stack[top1]=ele;
    top1++;
}
void push2(int ele){
    //code for two stacks  first starting from 0 and other from n/2

    // if(top2==n){
    //     return;
    // }

    //code for two stacks  first starting from 0 and other from n(from last)

    if(top2<top1){
        return;
    }
    stack[top2]=ele;
    top2--;
}
int pop1(){

    if(top1==0){
        return -1;
    }
    top1--;
    return stack[top1];
}
int pop2(){

    // if(top2==n/2){
    //     return -1;
    // }
    // top2--;
    if(top2==n-1){
        return -1;
    }
    top2++;
    return stack[top2];
}

int main(){
    n=5;
    top1=0;
    top2=n-1;
  push1(10);
  push1(20);
  push2(30);
  push2(40);
  push2(50);
cout<<pop2();

}