#include <iostream>
using namespace std;

double pourwater(double water, int r, int c) {
    if (r == 0 && c == 0) 
    {
        return min(water, 1.0);  
    }

    if (c < 0 || c > r) 
    {
        return 0; 
    }

     if (water > 1.0) {
        double extra = water - 1.0;  
        return 1.0 + pourwater(extra / 2.0, r - 1, c - 1) + pourwater(extra / 2.0, r, c - 1);
    }
    
    return water;  
}

 int main() {
    double waterAmount = 2.0;  
    int row = 1;  
    int column = 1;  

    double result = pourwater(waterAmount, row, column);  
    cout << "Total water at row " << row << ", column " << column << ": " << result << endl;

    return 0;  
}
