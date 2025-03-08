#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& vec,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;

    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++){
        L[i]=vec[l+i];
    }

    for(int i=0;i<n2;i++){
        R[i]=vec[m+i+1];
    }

int i=0;
int j=0;
int k=l;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            vec[k]=L[i];
            i++;
        }else{
            vec[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        vec[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        vec[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& vec,int l,int r){
    if(l<r){
        int m=(l+r)/2;

        mergesort(vec,l,m);
        mergesort(vec,m+1,r);
        merge(vec,l,m,r);
    }
}

int main(){
    vector<int> vec={3,1,4,7,6,8};
    mergesort(vec,0,vec.size()-1);

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

}