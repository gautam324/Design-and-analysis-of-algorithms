#include <iostream>
#include <vector>

using namespace std;

int minMatrixMultiplications(vector<pair<int, int>>& matrices) {
    int n = matrices.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + matrices[i].first * matrices[k].first * matrices[j].second);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> matrices(n);
    for (int i = 0; i < n; ++i) {
        cin >> matrices[i].first >> matrices[i].second;
    }

    int minOperations = minMatrixMultiplications(matrices);

    cout << minOperations << endl;

    return 0;
}
