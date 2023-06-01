#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void findProductPairs(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, pair<int, int>> productMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = arr[i] * arr[j];
            if (productMap.find(product) == productMap.end()) {
                productMap[product] = make_pair(i, j);
            } else {
                auto pair1 = productMap[product];
                auto pair2 = make_pair(i, j);
                cout << arr[pair1.first] << " " << arr[pair1.second] << endl;
                cout << arr[pair2.first] << " " << arr[pair2.second] << endl;
                return;
            }
        }
    }

    cout << "No such pairs found" << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Output:" << endl;
    findProductPairs(arr);

    return 0;
}