#include <iostream>
#include <string>
using namespace std;

string string_sum(string s1, string s2) {
    if (s1.size() < s2.size()) {
        swap(s1, s2);
    }
    
    int m = s1.size();
    int n = s2.size();
    
    string ans = "";
    int carry = 0;
    
    // Add digits of s1 and s2 starting from the rightmost digit
    for (int i = 0; i < n; i++) {
        int ds = ((s1[m - 1 - i] - '0') + (s2[n - 1 - i] - '0') + carry) % 10;
        carry = ((s1[m - 1 - i] - '0') + (s2[n - 1 - i] - '0') + carry) / 10;
        ans = char(ds + '0') + ans;
    }
    
    // Add remaining digits of s1 if s2 is shorter
    for (int i = n; i < m; i++) {
        int ds = (s1[m - 1 - i] - '0' + carry) % 10;
        carry = (s1[m - 1 - i] - '0' + carry) / 10;
        ans = char(ds + '0') + ans;
    }
    
    // If there's still a carry left, prepend it to the result
    if (carry) {
        ans = char(carry + '0') + ans;
    }
    
    return ans;
}

// Function to check if the sum property holds for a specific partition of the string
bool checkSum(string s, int b, int l1, int l2) {
    string s1 = s.substr(b, l1);       // First part
    string s2 = s.substr(b + l1, l2);  // Second part
    string s3 = string_sum(s1, s2);    // Sum of s1 and s2
    
    int s3_len = s3.size();
    
    // Check if the length of s3 exceeds the remaining length of the string
    if (s3_len > s.size() - l1 - l2 - b) {
        return false;
    }
    
    // Check if the sum matches the next part of the string
    if (s3 == s.substr(b + l1 + l2, s3_len)) {
        // If we have reached the end of the string, it's a valid sum string
        if (b + l1 + l2 + s3_len == s.size()) {
            return true;
        }
        // Recursively check for the next parts of the string
        return checkSum(s, b + l1 + l2, l2, s3_len);
    }
    
    return false;
}

// Helper function to add two numeric strings

// Function to check if a string is a sum string
int isSumString(string S) {
    int n = S.size();
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j < n; j++) {  // Fixed inner loop to use j as the variable
            if (checkSum(S, 0, i, j)) {
                return 1;
            }
        }
    }
    return 0;
}
// Main function
int main() {
    string S;
    cout << "Enter the string: ";
    cin >> S;

    // Check if the input string is a sum string
    if (isSumString(S)) {
        cout << "The string is a sum string!" << endl;
    } else {
        cout << "The string is not a sum string." << endl;
    }

    return 0;
}
