#include<iostream>
using namespace std;
void insert(int arr[],int &n,int pos,int val){
    for(int i=n;i>=pos-1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=val;
    n++;
    }
void delete1(int arr[],int &n,int pos){
        for(int i=pos-1;i<n;i++){
            arr[i]=arr[i+1];
        }
        n--;
}
void display(int arr[],int &n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val,pos;
    cin>>val>>pos;
    insert(arr,n,pos,val);
    display(arr,n);
    int del;
    cin>>del;
    delete1(arr,n,del);
    display(arr,n);

}
