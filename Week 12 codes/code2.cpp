
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

void knapsack(int n, const vector<int>& weights, const vector<int>& values, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<Item> selectedItems;
    int w = capacity;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back({weights[i - 1], values[i - 1]});
            w -= weights[i - 1];
        }
    }

    cout << dp[n][capacity] << endl;
    cout << "List of selected items:" << endl;
    for (const auto& item : selectedItems) {
        cout << "Weight: " << item.weight << ", Value: " << item.value << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int capacity;
    cin >> capacity;

    knapsack(n, weights, values, capacity);

    return 0;
}
