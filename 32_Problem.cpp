#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int startTime;
    int finishTime;
    int index;

    Activity(int start, int finish, int idx) : startTime(start), finishTime(finish), index(idx) {}
};

bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.finishTime < a2.finishTime;
}

void selectActivities(int n, const vector<int>& startTimes, const vector<int>& finishTimes) {
    vector<Activity> activities;
    for (int i = 0; i < n; i++) {
        activities.emplace_back(startTimes[i], finishTimes[i], i + 1);
    }

    sort(activities.begin(), activities.end(), compareActivities);

    vector<int> selectedActivities;
    selectedActivities.push_back(activities[0].index);
    int lastFinishTime = activities[0].finishTime;

    for (int i = 1; i < n; i++) {
        if (activities[i].startTime >= lastFinishTime) {
            selectedActivities.push_back(activities[i].index);
            lastFinishTime = activities[i].finishTime;
        }
    }

    cout << "No. of non-conflicting activities: " << selectedActivities.size() << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < selectedActivities.size(); i++) {
        cout << selectedActivities[i];
        if (i != selectedActivities.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<int> startTimes(n);
    cout << "Enter the starting times of activities: ";
    for (int i = 0; i < n; i++)
        cin >> startTimes[i];

    vector<int> finishTimes(n);
    cout << "Enter the finishing times of activities: ";
    for (int i = 0; i < n; i++)
        cin >> finishTimes[i];

    selectActivities(n, startTimes, finishTimes);

    return 0;
}
