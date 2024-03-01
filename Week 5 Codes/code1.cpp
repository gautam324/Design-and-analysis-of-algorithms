#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<char, int> findMaxOccurrence(const vector<char>& arr) {
    const int CHAR_RANGE = 256; 

    vector<int> count(CHAR_RANGE, 0);

    for (char c : arr) {
        count[c]++;
    }

    char maxChar = arr[0];
    int maxCount = count[arr[0]];

    for (char c = 'a'; c <= 'z'; ++c) {
        if (count[c] > maxCount) {
            maxCount = count[c];
            maxChar = c;
        }
    }

    return make_pair(maxChar, maxCount);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<char> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        pair<char, int> result = findMaxOccurrence(arr);

        if (result.second > 1) {
            cout << result.first << " - " << result.second << endl;
        } else {
            cout << "No Duplicates Present" << endl;
        }
    }

    return 0;
}



