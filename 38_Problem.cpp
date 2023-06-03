#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int longestCommonSubsequence(string sequence1, string sequence2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (sequence1[m-1] == sequence2[n-1])
        return dp[m][n] = 1 + longestCommonSubsequence(sequence1, sequence2, m-1, n-1, dp);
    else
        return dp[m][n] = max(longestCommonSubsequence(sequence1, sequence2, m-1, n, dp),
                              longestCommonSubsequence(sequence1, sequence2, m, n-1, dp));
}

string longestCommonSubsequenceString(string sequence1, string sequence2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return "";

    if (sequence1[m-1] == sequence2[n-1])
        return longestCommonSubsequenceString(sequence1, sequence2, m-1, n-1, dp) + sequence1[m-1];
    else {
        if (dp[m-1][n] > dp[m][n-1])
            return longestCommonSubsequenceString(sequence1, sequence2, m-1, n, dp);
        else
            return longestCommonSubsequenceString(sequence1, sequence2, m, n-1, dp);
    }
}

int main() {
    string sequence1, sequence2;
    cout << "Enter Sequence1: ";
    cin >> sequence1;
    cout << "Enter Sequence2: ";
    cin >> sequence2;

    int m = sequence1.length();
    int n = sequence2.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

    int length = longestCommonSubsequence(sequence1, sequence2, m, n, dp);
    string lcs = longestCommonSubsequenceString(sequence1, sequence2, m, n, dp);

    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length = " << length << endl;

    return 0;
}
