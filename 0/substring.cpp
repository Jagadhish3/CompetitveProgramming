#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1="aabaaaabcdaaazzzz";
    string s2="aaabcdaa";

    vector<int> vec(s2.length(),0);

    int jj=0;
    int ii=1;

    while (ii < vec.size()) {
        if (s1[jj] == s1[ii]) {
            jj++;
            vec[ii] = jj;
            ii++;
        } else if (jj > 0) {
            jj = vec[jj - 1];
        } else {
            vec[ii] = 0;
            ii++;
        }
    }

    int i=0;
    int j=0;
    int pos=-1;

    while (i<s1.length() && j<s2.length()) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
            if (j == s2.length()) {
        pos= i - s2.length();
        break; 
    } 
        } else if(s1[i]!=s2[j] && j>0) {
            j=vec[j-1];        
        }else if(s1[i]!=s2[j]&& j==0){
            i++;
        }
    }

    
        cout << pos; 
    

    }