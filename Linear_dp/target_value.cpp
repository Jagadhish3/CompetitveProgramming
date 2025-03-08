#include<iostream>
using namespace std;

bool target(int arr[],int size,int num){
        int l = 0;
        int r = size-1;
       
while(l < r){
        int sum = arr[l] + arr[r];
        if(sum == num){
            return true;
        } else if(sum < num){
            l++;
        } else {
            r--;
        }
    }
    
    return false;
}

int main(){
        int arr[5] = {1,2,3,4,5};
        bool res = target(arr,5,7);
        if(res){
            cout<<"Found";
        }else{
            cout<<"Not found";
        }
}