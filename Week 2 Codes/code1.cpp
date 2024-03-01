#include <iostream>
#include <vector>

using namespace std;


int binarySearch(vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int findLeftmostOccurrence(vector<int>& arr, int key) {
    int index = binarySearch(arr, key);
    if (index == -1) {
        return -1; 
    }

    while (index > 0 && arr[index - 1] == key) {
        index--;
    }

    return index;
}

int findRightmostOccurrence(vector<int>& arr, int key) {
    int index = binarySearch(arr, key);
    if (index == -1) {
        return -1; 
    }

    while (index < arr.size() - 1 && arr[index + 1] == key) {
        index++;
    }

    return index;
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

        int leftmost = findLeftmostOccurrence(arr, key);
        int rightmost = findRightmostOccurrence(arr, key);

        if (leftmost != -1) {
            int copies = rightmost - leftmost + 1;
            cout << "Key element " << key << " found with " << copies << " copies." << endl;
        } else {
            cout << "Key element " << key << " not found." << endl;
        }
    }

    return 0;
}
