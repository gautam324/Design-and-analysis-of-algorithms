#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

int partition(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swaps++;
            swap(arr[i], arr[j]);
        }
    }
    swaps++;
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        quickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

void randomizedQuickSort(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    if (low < high) {

        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);

        int pivotIndex = partition(arr, low, high, comparisons, swaps);

        randomizedQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        randomizedQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
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

        long long comparisons = 0;
        long long swaps = 0;

        randomizedQuickSort(arr, 0, n - 1, comparisons, swaps);

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
