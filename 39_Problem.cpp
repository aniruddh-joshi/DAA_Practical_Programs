#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

void knapsack(int capacity, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], items[i - 1].value + dp[i - 1][j - items[i - 1].weight]);
            }
        }
    }

    // Find the selected items
    int maxValue = dp[n][capacity];
    vector<Item> selectedItems;
    int i = n, j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(items[i - 1]);
            j -= items[i - 1].weight;
        }
        i--;
    }

    // Output the results
    cout << "Maximum value: " << maxValue << endl;
    cout << "Selected items:" << endl;
    for (const Item& item : selectedItems) {
        cout << "Weight: " << item.weight << ", Value: " << item.value << endl;
    }
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].weight;
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].value;
    }

    int capacity;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    knapsack(capacity, items);

    return 0;
}
