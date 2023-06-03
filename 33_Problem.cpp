#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int timeTaken;
    int deadline;
    int index;

    Task(int t, int d, int i) : timeTaken(t), deadline(d), index(i) {}
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.deadline < task2.deadline;
}

void selectTasks(int n, vector<int>& timeTaken, vector<int>& deadlines) {
    // Create a vector of Task objects
    vector<Task> tasks;
    for (int i = 0; i < n; i++) {
        tasks.emplace_back(timeTaken[i], deadlines[i], i + 1);
    }

    // Sort the tasks based on the deadlines
    sort(tasks.begin(), tasks.end(), compareTasks);

    // Select the tasks based on the deadlines
    vector<int> selectedTasks;
    int totalTime = 0;
    for (const Task& task : tasks) {
        if (totalTime + task.timeTaken <= task.deadline) {
            selectedTasks.push_back(task.index);
            totalTime += task.timeTaken;
        }
    }

    // Print the result
    cout << "Max number of tasks = " << selectedTasks.size() << endl;
    cout << "Selected task numbers: ";
    for (int i = 0; i < selectedTasks.size(); i++) {
        cout << selectedTasks[i];
        if (i != selectedTasks.size() - 1)
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
