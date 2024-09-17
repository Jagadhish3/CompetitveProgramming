#include<iostream>
using namespace std;

int main(){
   
    int arr[3][3] = {{1 ,2, 3},{4,5,6},{7,8,9}};
    int n = 3;
    int m = 3;

    int num = m*n;
    int  row = 0 ;
    int col = 0;
    int dir = 0;
    int i=0;
    int arr1[num];
   while(i<num){
        arr1[i] = arr[row][col];
        i++;
        if(dir==0){
        if(col==n-1){
            dir = 1;
            row++;
        }else if(row==0){
            dir = 1;
            col++;
        }else{
            row--;
            col++;
        }

    }else{
        if(row==m-1){
            col++;
            dir=0;
        }else if(col==0){
            row++;
            dir=0;
        }else{
            row++;
            col--;
        }
    }
    }
    for(int i=0;i<num;i++){
        cout<<arr1[i]<<" ";
    }
    
}