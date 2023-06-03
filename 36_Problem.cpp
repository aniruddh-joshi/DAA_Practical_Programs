#include <iostream>
#include <vector>
using namespace std;

int countWaysHelper(vector<int>& coins, int n, int sum, vector<vector<int>>& dp) {
    if (sum == 0)
        return 1;

    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int ways = countWaysHelper(coins, n - 1, sum, dp);
    if (coins[n - 1] <= sum)
        ways += countWaysHelper(coins, n, sum - coins[n - 1], dp);

    return dp[n][sum] = ways;
}

int countWays(vector<int>& coins, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return countWaysHelper(coins, n, sum, dp);
}

int main() {
    int numCoins;
    cout << "Enter the number of coins available: ";
    cin >> numCoins;

    vector<int> coins(numCoins);
    cout << "Enter the value of each coin: ";
    for (int i = 0; i < numCoins; i++)
        cin >> coins[i];

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    int ways = countWays(coins, numCoins, targetSum);
    cout << "Number of ways to make the sum: " << ways << endl;

    return 0;
}
