#include <iostream>
#include <vector>
using namespace std;

int countWays (int coins[], int m, int N) 
{
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++) 
    {
        for (int j = coins[i]; j <= N; j++) 
        {
            dp[j] += dp[j - coins[i]]; 
        }  
    }
    return dp[N];
}
int main() 
{
    int m, N;
    cout << "Enter number of coins: ";
    cin >> m;
    int coins[100];
    cout << "Enter coin denominations: ";
    for (int i = 0; i < m; i++) 
    { 
        cin >> coins[i];  
    }
    cout << "Enter amount: ";
    cin >> N;
    cout << "Number of ways = " << countWays (coins, m, N);
    return 0;
}