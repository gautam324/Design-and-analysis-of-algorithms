#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countPairsWithDifferenceK(vector<int>& arr, int K) {
    unordered_map<int, int> freqMap;
    int count = 0;

    for (int num : arr) {
        freqMap[num]++;
    }

    for (int num : arr) {
        int complement1 = num - K;
        int complement2 = num + K;

        if (freqMap.find(complement1) != freqMap.end()) {
            count += freqMap[complement1];
        }

        if (K != 0 && freqMap.find(complement2) != freqMap.end()) {
            count += freqMap[complement2];
        }

    
        if (K == 0) {
            count -= freqMap[num];
        }
    }


    return count / 2;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, K;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cin >> K;

        int pairsCount = countPairsWithDifferenceK(arr, K);

        cout << "Number of pairs with difference " << K << ": " << pairsCount << endl;
    }

    return 0;
}
