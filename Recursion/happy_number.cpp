#include<iostream>
using namespace std;

int sum_of_squares(int num){

    int sum=0;
    while(num!=0){
        int t = num%10;
        sum+=(t*t);
        num/=10;
    }
    return sum;
}

bool ishappy(int num){
    int first = num;
    int last = num;

    do{
        first=sum_of_squares(first);
        last=sum_of_squares(sum_of_squares(last));
    }while(first!=last);

    return first==1;
}
int next_happy_number(int n) {
    n++; 
    while (!ishappy(n)) {
        n++;
    }
    return n;
}


int main(){
    int n;
    cin>>n;
    if(ishappy(n)){
        cout<<"Happy number";
    }else{
        cout<<"Not a happy number";
    }
}