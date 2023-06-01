#include <bits/stdc++.h>

using namespace std;

void checkDuplicates(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    for (int i = 0; i < arr.size(); i++) {
        if (i > k) {
            freq[arr[i-k-1]]--;
            if (freq[arr[i-k-1]] == 0)
                freq.erase(arr[i-k-1]);
        }

        freq[arr[i]]++;
        if (freq[arr[i]] > 1) {
            cout << "Duplicate present in window " << k << endl;
            return;
        }
    }
    cout << "Duplicate not present in window " << k << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> k;
        checkDuplicates(arr, k);
    }
    
    return 0;
}