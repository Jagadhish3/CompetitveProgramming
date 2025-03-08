#include<bits/stdc++.h>

using namespace std;

void FermatFactors(int n) 
{ 
    if(n <= 0) 
    { 
        cout << "[" << n << "]"; 
        return; 
    } 

    if((n & 1) == 0) 
    { 
        cout << "[" << n / 2.0 << "," << 2 << "]"; 
        return; 
    } 

    int a = ceil(sqrt(n)); 

    if(a * a == n) 
    { 
        cout << "[" << a << "," << a << "]"; 
        return; 
    } 

    int b; 
    while(true) 
    { 
        int b1 = a * a - n; 
        b = (int)sqrt(b1); 

        if(b * b == b1) 
            break; 
        else
            a += 1; 
    } 

    cout << "[" << (a - b) << "," << (a + b) << "]"; 
    return; 
} 

int main() 
{
    FermatFactors(6557);
    return 0;
}