#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[5]={9,8,7,1,5};
    int l[5];
    int r[5];
    int p = 1;
    l[0]=1;
    r[4]=1;
    for(int i=1;i<5;i++){
        
            p=p*arr[i-1];
        
        l[i]=p;
        
    }
p=1;
    for(int i=3;i>=0;i--){
        
            p=p*arr[i+1];
                r[i]=p;
           }
         int  res[5];
for(int i=0;i<5;i++){
res[i]=l[i]*r[i];
}
}