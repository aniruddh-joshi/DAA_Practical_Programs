#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& set, int n, int sum, vector<vector<int>>& dp) {
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (set[n-1] <= sum)
        return dp[n][sum] = isSubsetSum(set, n-1, sum-set[n-1], dp) || isSubsetSum(set, n-1, sum, dp);

    return dp[n][sum] = isSubsetSum(set, n-1, sum, dp);
}

bool canPartition(vector<int>& set) {
    int n = set.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += set[i];

    if (sum % 2 != 0)
        return false;

    vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, -1));

    return isSubsetSum(set, n, sum/2, dp);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++)
        cin >> set[i];

    bool possible = canPartition(set);

    if (possible)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
