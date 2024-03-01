#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < n2; ++j) {
        right[j] = arr[mid + 1 + j];
    }

    long long inversions = 0;

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, int low, int high) {
    long long inversions = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);

        inversions += merge(arr, low, mid, high);
    }

    return inversions;
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

        long long comparisons = mergeSort(arr, 0, n - 1);

        cout << "Sorted Array: ";
        for (int elem : arr) {
            cout << elem << " ";
        }
        cout << endl;

        cout << "Comparisons: " << comparisons << endl;

        cout << "Inversions: " << comparisons << endl;
    }

    return 0;
}
