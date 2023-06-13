#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

void fractionalKnapsack(Item items[], int numItems, int capacity) {
    sort(items, items + numItems, compare);

    double totalValue = 0.0;
    double totalWeight = 0.0;

    for (int i = 0; i < numItems; i++) {
        if (items[i].weight <= capacity && capacity > 0) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
            capacity -= items[i].weight;
        } else {
            totalValue += (static_cast<double>(items[i].value) * capacity) / items[i].weight;
            totalWeight += capacity;
            capacity = 0;
        }

        if (capacity == 0)
            break;
    }

    cout << fixed << setprecision(2);  // Set decimal precision for output

    cout << "Maximum value: " << totalValue << endl;

    cout << "item-weight" << endl;
    for (int i = 0; i < numItems; i++) {
        if (items[i].weight <= totalWeight) { // Update the condition here
            cout << i + 1 << "-" << items[i].weight << endl;
        } else {
            cout << i + 1 << "-" << (static_cast<double>(items[i].value) * totalWeight) / items[i].weight << endl;
        }

        if (totalWeight == capacity)
            break;
    }
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    Item items[numItems];

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

    for (int i = 0; i < numItems; i++) {
        items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
    }

    fractionalKnapsack(items, numItems, capacity);

    return 0;
}
