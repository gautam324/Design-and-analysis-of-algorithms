#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swaps++; 
            swap(arr[i], arr[minIndex]);
        }
    }
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

        int comparisons = 0;
        int swaps = 0;

        selectionSort(arr, comparisons, swaps);

        cout << "Sorted Array: ";
        for (int elem : arr) {
            cout << elem << " ";
        }
        cout << endl;

        cout << "Comparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
    }

    return 0;
}
