#include <iostream>
#include <vector>

using namespace std;

int countWays(int coins[], int n, int N) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= N; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[N];
}

int main() {
    int n;
    cin >> n;

    int coins[n];
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int N;
    cin >> N;

    int ways = countWays(coins, n, N);

    cout << ways << endl;

    return 0;
}

