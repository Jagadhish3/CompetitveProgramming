#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Bag {
    int weight;
    int value;
    double profit;
}items[3];

class A {
    public:
    vector<Bag> vec;

    void push(int wt, int val) {
        vec.push_back({wt, val});
    }

    vector<pair<double, int>> val_wt(int wt[], int val[], int n) {
        vector<pair<double, int>> vec;
        
        for (int i = 0; i < n; i++) {
            double ratio = double(val[i]) / wt[i];
            vec.push_back({ratio, i}); 
        }

        sort(vec.begin(), vec.end(), greater<pair<double, int>>());
        return vec;
    }

    double profit(int wt[], int val[], int n, int W) {
        vector<pair<double, int>> ratios = val_wt(wt, val, n);
        double totalProfit = 0.0;

        for (int i = 0; i < n; i++) {
            int index = ratios[i].second; 

            if (wt[index] <= W) {
                W -= wt[index];
                totalProfit += val[index];
            } else {
                // Take the fraction of the item if it doesn't fit completely
                totalProfit += val[index] * (double(W) / wt[index]);
                break;  // Bag is full, stop
            }
        }

        return totalProfit;  // Return the maximum profit
    }
};

int main() {
    A obj;

    // Items (weights and values)
    int weights[] = {10, 20, 30};
    int values[] = {50, 70, 90};
    int W = 50;  // Maximum weight capacity of the knapsack
    int n = sizeof(weights) / sizeof(weights[0]);

    // Calculate the maximum profit
    double maxProfit = obj.profit(weights, values, n, W);

    // Output the result
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}

bool cmp(Bag a,Bag b){
    a.profit=(double)a.value/a.weight;
    b.profit=(double)b.value/b.weight;

    return a.profit>b.profit;

}

int main(){
    int wt[]={10,20,30};
    int val[]={50,70,90};

    int w=50;

    for(int i=0;i<3;i++){
        items[i].weight =wt[i];
        items[i].value=val[i];
    }

    sort(items,items+3,cmp);

    for(int i=0;i<3;i++){
        if(items[i].weight<=w){
            profit=profit+items[i].value;
            w=w-itrms[i].weight;
        }else{
            profit+
        }
    }
}