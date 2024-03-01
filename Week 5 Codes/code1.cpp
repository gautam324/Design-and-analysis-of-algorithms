#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasPairWithSum(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == key) {
            return true; 
        } else if (currentSum < key) {
            left++;
        } else {
            right--; 
        }
    }
    
    return false; 
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, key;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cin >> key;
        sort(arr.begin(), arr.end());

        if (hasPairWithSum(arr, key)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
