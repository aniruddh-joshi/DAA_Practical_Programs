#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<pair<int, int>>& matrices, int i, int j, vector<vector<int>>& dp) {
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int operations = matrixChainMultiplication(matrices, i, k, dp) + matrixChainMultiplication(matrices, k + 1, j, dp) + matrices[i].first * matrices[k].second * matrices[j].second;
        dp[i][j] = min(dp[i][j], operations);
    }

    return dp[i][j];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<pair<int, int>> matrices(n);
    cout << "Enter the dimensions of each matrix (aXb): ";
    for (int i = 0; i < n; i++)
        cin >> matrices[i].first >> matrices[i].second;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int minOperations = matrixChainMultiplication(matrices, 0, n - 1, dp);
    cout << "Minimum number of operations: " << minOperations << endl;

    return 0;
}
