#include <iostream>
#include <vector>
using namespace std;

void selectTasks(int n, vector<int>& timeTaken, vector<int>& deadlines) {
    int count = 0;
    vector<int> selectedTasks;
    int totalTime = 0;

    for (int i = 0; i < n; i++) {
        if (totalTime + timeTaken[i] <= deadlines[i]) {
            count++;
            selectedTasks.push_back(i + 1);
            totalTime += timeTaken[i];
        }
    }

    cout << "Max number of tasks = " << count << endl;
    cout << "Selected task numbers: ";
    for (int i = 0; i < count; i++) {
        cout << selectedTasks[i];
        if (i != count - 1)
            cout << ", ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the total number of tasks: ";
    cin >> n;

    vector<int> timeTaken(n);
    cout << "Enter the time taken for each task: ";
    for (int i = 0; i < n; i++)
        cin >> timeTaken[i];

    vector<int> deadlines(n);
    cout << "Enter the deadlines for each task: ";
    for (int i = 0; i < n; i++)
        cin >> deadlines[i];

    selectTasks(n, timeTaken, deadlines);

    return 0;
}
