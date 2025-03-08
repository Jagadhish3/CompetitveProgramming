/*     n=4
     4 4 4 4
      3 3 3
       2 2
        1  

        *
       * *
      * *  *  */

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(j<=n-i){
    //             cout<<" ";
    //         }
    //         else{
    //             cout<<i<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         if((i+j)%2==0){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }


    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i==1 || j==n || (i==j)){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }


    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i==n || j==n || ((i+j)==(n+1))){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }


    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(j<=n-i){
    //             cout<<" ";
    //         }
    //         else if((i+j)==(n+1) || j==n || i==n){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(j<=n-i){
    //             cout<<" ";
    //         }
    //         else if((i+j)==(n+1) || j==n || i==n-2){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(j==1 || i==n || j==i){
    //             cout<<"* ";
    //         }else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
            
    //         if(j==n || (i+j)==n+1){
    //             cout<<"* ";
    //         }else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((j==1) && ( i==1 || i==n  )){
                cout<<" ";
            }
            else if(j==1|| i==1 || i==n ){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}