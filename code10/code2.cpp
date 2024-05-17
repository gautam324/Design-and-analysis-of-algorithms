#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int time;
    int deadline;
};

bool compare(Task a, Task b) {
    return a.deadline < b.deadline;
}

int maxTasksCompleted(int n, vector<int>& times, vector<int>& deadlines) {
    vector<Task> tasks(n);

    for (int i = 0; i < n; ++i) {
        tasks[i].time = times[i];
        tasks[i].deadline = deadlines[i];
    }

    sort(tasks.begin(), tasks.end(), compare);

    int currentTime = 0;
    int maxTasks = 0;

    for (int i = 0; i < n; ++i) {
        if (currentTime + tasks[i].time <= tasks[i].deadline) {
            currentTime += tasks[i].time;
            maxTasks++;
        }
    }

    return maxTasks;
}

int main() {
    int n;
    cin >> n;

    vector<int> times(n);
    vector<int> deadlines(n);

    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> deadlines[i];
    }

    int maxCompleted = maxTasksCompleted(n, times, deadlines);
    cout << maxCompleted << endl;

    return 0;
}
