
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<bool, int> findMajorityElement(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> count;

    for (int num : arr) {
        count[num]++;
        if (count[num] > n / 2) {
            return {true, num};
        }
    }

    return {false, -1};
}

double findMedian(const vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    pair<bool, int> majority = findMajorityElement(arr);
    if (majority.first) {
        cout << "yes" << endl;
        cout << "Majority element: " << majority.second << endl;
    } else {
        cout << "no" << endl;
    }

    double median = findMedian(arr);
    cout << "Median: " << median << endl;

    return 0;
}
