#include<bits/stdc++.h>
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> trustCounts(N + 1, 0);

    for(auto &t : trust) {
        trustCounts[t[0]]--; // The person trusts someone, reduce count
        trustCounts[t[1]]++; // The person is trusted, increase count
    }

    for(int i = 1; i <= N; i++) {
        if(trustCounts[i] == N - 1) // The town judge should be trusted by N-1 people and trust no one
            return i;
    }

    return -1; // No town judge found
}

int main() {
    int N, E;
    cout << "Enter number of people in town: ";
    cin >> N;

    cout << "Enter number of trust relationships: ";
    cin >> E;

    vector<vector<int>> trust(E, vector<int>(2));

    cout << "Enter trust relationships (a b means a trusts b):" << endl;
    for(int i = 0; i < E; i++)
        cin >> trust[i][0] >> trust[i][1];

    int judge = findJudge(N, trust);
    
    if(judge == -1)
        cout << "No town judge found." << endl;
    else
        cout << "The town judge is: " << judge << endl;

    return 0;
}
