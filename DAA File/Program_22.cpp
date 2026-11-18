#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int n,arr[100], dp[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        dp[i] = 1;   
    }
    
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j]) 
            { 
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        } 
    }
    
    int maxLength = 0;
    for (int i = 0; i < n; i++) 
    { 
        maxLength = max(maxLength, dp[i]); 
    }
    
    cout << "Length of Longest Increasing Subsequence = "<< maxLength << endl;
    return 0;
}