#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    
    // Reading the 2D array
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    unordered_map<int, int> freq; // To store the number of occurrences of each element in the first row

    // Insert all elements from the first row into the map with their respective counts
    for(int i = 0; i < n; i++){
        freq[arr[0][i]]++; // Increment frequency for each occurrence of the element
    }

    // Loop through the rest of the rows
    for(int i = 1; i < m; i++){ // Start from the second row
        unordered_map<int, int> rowFreq; // Track how many times each element appears in the current row
        
        for(int j = 0; j < n; j++){
            int element = arr[i][j];
            
            // If the element is in the freq map (i.e., it was in the first row), update the count in rowFreq
            if(freq.find(element) != freq.end()){
                rowFreq[element]++;
            }
        }
        
        // Update freq map to reflect the minimum occurrences across all rows so far
        for(auto &f : freq){
            f.second = min(f.second, rowFreq[f.first]); // Keep only the occurrences that appear in every row
        }
    }

    // Output the elements from the first row that appear in every row, respecting their occurrences
    cout << "Elements in the first row that appear in every row are: ";
    bool found = false;
    for(auto it : freq){
        while(it.second-- > 0){ // Output the element for each occurrence that survived across all rows
            cout << it.first << " ";
            found = true;
        }
    }

    if (!found){
        cout << "None";
    }
    cout << endl;

    return 0;
}