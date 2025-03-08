#include<iostream>
using namespace std;
int main(){
    string s1 = "listen";
    string s2 = "silen";

    int arr[26]={};
    // if(s1.length()!=s2.length()){
    //     cout<<"Not anagram";
    //     return 0;
    // }
    for(char c:s1){
            arr[c-'a']++;
    }
    for(char c:s2){
        arr[c-'a']--;
    }
    // bool res = true;
    int count=0;
    for(int i=0;i<26;i++){
        // if(arr[i]!=0){
        //     res = false;
        //     break;
        // }
        count=count+abs(arr[i]);
    }
    // if(res){
    //     cout<<"anagram";
    // }else{
    //     cout<<"Not anagram";
    // }
    cout<<count;
    return 0;

}