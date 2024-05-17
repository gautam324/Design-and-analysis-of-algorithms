
#include <iostream>
#include <vector>

using namespace std;

pair<int, string> longestCommonSubsequence(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string subsequence;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            subsequence = s1[i - 1] + subsequence;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {dp[m][n], subsequence};
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    pair<int, string> result = longestCommonSubsequence(s1, s2);

    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}
