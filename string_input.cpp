#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s ="{1,2,3,4}";
    string s1 = "";
    vector<int> vec; 
    for(char ch:s){
        if(ch==','){
            vec.push_back(stoi(s1));
            s1="";
        }
        else{
            s1+=ch;
        }
    }
    vec.push_back(stoi(s1));
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}