#include<bits/stdc++.h>
using namespace std;

int main(){

    string s1;
    cin>>s1;

    vector<int> vec(s1.length(),0);

    int j=0;
    int i=1;

    while (i < vec.size()) {
        if (s1[j] == s1[i]) {
            j++;
            vec[i] = j;
            i++;
        } else if (j > 0) {
            j = vec[j - 1];
        } else {
            vec[i] = 0;
            i++;
        }
    }

    cout<<vec[vec.size()-1];
}