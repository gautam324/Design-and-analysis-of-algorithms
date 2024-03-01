#include <iostream>
#include <vector>

using namespace std;

bool findTriplet(vector<int>& arr) {
    int n = arr.size();

    for (int k = n - 1; k >= 0; --k) {
        int target = arr[k];
        int i = 0;
        int j = k - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == target) {
                cout << "Triplet found: " << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
                return true;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        if (!findTriplet(arr)) {
            cout << "No triplet found" << endl;
        }
    }

    return 0;
}
