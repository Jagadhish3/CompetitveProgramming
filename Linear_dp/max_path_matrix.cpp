#include<iostream>
using namespace std;

string ls(string s){
    int n = s.length();
    string ss = "";
    if(n<=2){
        return s;
    }
    ss+=s[0];
    ss+=s[1];
    int i=0;
    int j=1;

    for(int k=2;k<n;k++){
        if(s[k]==s[i]||s[k]==s[j]){
            j++;
            if(j==n-1){
                ss="";
                for(int m=i;m<=j;m++){
                    ss+=s[m];
                }
            }
        }else{
            if(j-i+1 > ss.length()){
                ss="";
                for(int m=i;m<=j;m++){
                    ss+=s[m];
                }
            }
            i++;
            j++;
        }
    }
    return ss;

}
int main(){
    string s1;
    cin>>s1;

    cout<<ls(s1);
}

// #include<iostream>
// #include<cstring>
// using namespace std;

// char* ls(char s[], int n) {
//     static char ss[100];
//     int ss_len = 0;

//     if (n <= 2) {
//         strcpy(ss, s);
//         return ss;
//     }

//     ss[0] = s[0];
//     ss[1] = s[1];
//     ss_len = 2;

//     int i = 0, j = 1;

//     for (int k = 2; k < n; k++) {
//         if (s[k] == s[i] || s[k] == s[j]) {
//             j++;
//             if (j == n - 1) {
//                 ss_len = 0;
//                 for (int m = i; m <= j; m++) {
//                     ss[ss_len++] = s[m];
//                 }
//                 ss[ss_len] = '\0';
//             }
//         } else {
//             if (j - i + 1 > ss_len) {
//                 ss_len = 0;
//                 for (int m = i; m <= j; m++) {
//                     ss[ss_len++] = s[m];
//                 }
//                 ss[ss_len] = '\0';
//             }
//             i++;
//             j++;
//         }
//     }
//     return ss;
// }

// int main() {
//     char s1[100]; // Assuming max input length is 100
//     cin >> s1;

//     int n = strlen(s1); // Calculate length of input

//     cout << ls(s1, n);
// }
