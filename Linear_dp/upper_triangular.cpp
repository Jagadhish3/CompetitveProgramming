#include<iostream>
using namespace std;
// void upper(int arr[],int m,int n){
    
// }
// void lower(int arr[],int m,int n){
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(i<j){
//                 arr[i][j] = 0;
//             }
//         }
//     }
// }
int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i<=j){
                cout<<arr[i][j]<<" ";
            }else{
                break;
            }
        }
        cout<<endl;
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
}