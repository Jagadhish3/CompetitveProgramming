#include<iostream>
using namespace std;

int partition(int arr[],int p,int n){
    int pivot = arr[n-1];
    int start=p;
    int end=n;
    
    while(start<end){
        while(arr[start]<pivot){
            swap(arr[start],arr[end]);
            start++;
            end++;
        }

        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[start],pivot);
}

void quicksort(int arr[],int s,int e){
    if(s<e){
        int p= partition(arr,s,e);
        quicksort(arr,s,p-1);
        quicksort(arr,p,e);

    }
}

int main(){
    int a[5]={2,3,6,7,1};
    quicksort(a,0,5);

    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}