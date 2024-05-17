
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void selectNonConflictingActivities(int N, vector<int>& startTimes, vector<int>& finishTimes) {
    vector<Activity> activities(N);

    for (int i = 0; i < N; ++i) {
        activities[i].start = startTimes[i];
        activities[i].finish = finishTimes[i];
    }

    sort(activities.begin(), activities.end(), compare);

    int lastFinishTime = 0;
    vector<Activity> selectedActivities;
    for (int i = 0; i < N; ++i) {
        if (activities[i].start >= lastFinishTime) {
            selectedActivities.push_back(activities[i]);
            lastFinishTime = activities[i].finish;
        }
    }

    cout << "Number of non-conflicting activities: " << selectedActivities.size() << endl;

    cout << "List of selected activities:" << endl;
    for (const auto& activity : selectedActivities) {
        cout << "Start: " << activity.start << ", Finish: " << activity.finish << endl;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> startTimes(N);
    vector<int> finishTimes(N);

    for (int i = 0; i < N; ++i) {
        cin >> startTimes[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> finishTimes[i];
    }

    selectNonConflictingActivities(N, startTimes, finishTimes);

    return 0;
}
