#include<iostream>
using namespace std;

void toh(int n,char b, char a,char e){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<b<<" to "<<e<<endl;
        return;
    }
    else{
        toh(n-1,b,e,a);
        cout<<"Move disk "<<n<<" from "<<b<<" to "<<e<<endl;
        toh(n-1,a,b,e);
    }
}

int main(){
    int n;
    cin>>n;
    toh(n,'B','A','E');

    return 0;
}