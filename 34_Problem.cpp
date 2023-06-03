#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findMajorityElement(vector<int>& arr) {
    int n = arr.size();
    int candidate = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else {
            if (candidate == arr[i])
                count++;
            else
                count--;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return true;
    else
        return false;
}

int findMedian(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    else
        return arr[n / 2];
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool majorityExists = findMajorityElement(arr);
    int median = findMedian(arr);

    cout << "Majority element exists: ";
        if (majorityExists) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    cout << "Median of the array: " << median << endl;

    return 0;
}
