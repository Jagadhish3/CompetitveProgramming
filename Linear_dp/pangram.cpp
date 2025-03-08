#include<iostream>
#include<vector>
using namespace std;


int main(){
    string s1;
    getline(cin,s1);

    vector<int> arr(26,0);
    
    for(char c: s1){
        arr[c-'a']++;
    }
    
    // for(int i=0;i<26;i++){
    //     arr[s1[i]-'a']=s1[i]-'a';
        
    // }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            cout << (char)(i + 'a') << " ";
        }
    }
    return 0;
}