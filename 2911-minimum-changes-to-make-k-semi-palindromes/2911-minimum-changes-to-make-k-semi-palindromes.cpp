class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // Step 1: Precompute substring costs
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Check each group
                    for (int r = 0; r < d; r++) {

                        int l = i + r;
                        int right = i + r + ((len - 1) / d) * d;

                        // Count mismatched pairs
                        while (l < right) {
                            if (s[l] != s[right]) {
                                changes++;
                            }

                            l += d;
                            right -= d;
                        }
                    }

                    cost[i][i + len - 1] =
                        min(cost[i][i + len - 1], changes);
                }
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int j = 2 * parts; j <= n; j++) {

                for (int t = 2 * (parts - 1); t <= j - 2; t++) {

                    dp[parts][j] = min(
                        dp[parts][j],
                        dp[parts - 1][t] + cost[t][j - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna