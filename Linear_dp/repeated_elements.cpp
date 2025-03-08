#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int arr1[n];
    for(int i=0;i<n;i++){
        arr1[i] = arr[0][i];
    }
    vector<int> vec;
    for(int k=0;k<n;k++){
        int cnt =0;
        for(int i=1;i<m;i++){
            //bool flag = flase;
            for(int j=0;j<n;j++){
                 if(arr1[k]==arr[i][j]){
                    cnt++;
                    //flag=true;
                    arr[i][j] = -1;
                    break;
            }
        }
        //if(flag==flase){
        //break;
        //}
    }
    if(cnt==m-1){
        vec.push_back(arr1[k]);
    }
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}