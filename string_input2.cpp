#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s = "{{1,2},{3,4}}";
    string s1 = "";
    vector<vector<int>> vec; 
    vector<int> temp; // Temporary vector to store individual inner lists
    
    for(char ch : s){
        if(ch == '{'){ 
            // Ignore the opening curly brace
            continue;
        }
        else if(ch == ','){
            if(!s1.empty()) {  // If we have a number accumulated in s1
                temp.push_back(stoi(s1)); // Convert it and add to the temp vector
                s1 = ""; // Reset the string
            }
        }
        else if(ch == '}'){ 
            if(!s1.empty()) {  // Push the last number of the inner vector
                temp.push_back(stoi(s1));
                s1 = "";
            }
            // When we hit the closing curly brace, push temp into vec
            if(!temp.empty()){
                vec.push_back(temp);
                temp.clear(); // Clear for the next inner vector
            }
        }
        else {
            s1 += ch; // Accumulate the digits
        }
    }

    // Output the 2D vector
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
