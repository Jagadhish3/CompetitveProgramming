#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Box {
        int h, w, l; // h = height, w = width, l = length
    };

    static bool compare(const Box& a, const Box& b) {
        return (a.w * a.l) > (b.w * b.l);
    }

    int maxHeight(int height[], int width[], int length[], int n) {
        vector<Box> boxes;

        // Generate all rotations of the boxes
        for (int i = 0; i < n; i++) {
            boxes.push_back({height[i], max(width[i], length[i]), min(width[i], length[i])});
            boxes.push_back({width[i], max(height[i], length[i]), min(height[i], length[i])});
            boxes.push_back({length[i], max(height[i], width[i]), min(height[i], width[i])});
        }

        // Sort the boxes by base area (width * length) in descending order
        sort(boxes.begin(), boxes.end(), compare);

        int m = boxes.size();
        vector<int> dp(m);

        // Initialize dp array with the height of each box
        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i].h;
        }

        // Compute the maximum stack height
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[i].w < boxes[j].w && boxes[i].l < boxes[j].l) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].h);
                }
            }
        }

        // Find the maximum height in the dp array
        int maxHeight = 0;
        for (int i = 0; i < m; i++) {
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
    }
};

int main() {
    int n;
    cout << "Enter the number of boxes: ";
    cin >> n;

    int height[n], width[n], length[n];

    cout << "Enter height, width, and length of each box:\n";
    for (int i = 0; i < n; i++) {
        cin >> height[i] >> width[i] >> length[i];
    }

    Solution sol;
    int result = sol.maxHeight(height, width, length, n);

    cout << "The maximum height of the stack is: " << result << endl;

    return 0;
}
