class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if (costBoth >= cost1 + cost2) {
            ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }
        else {
            int common = min(need1, need2);
            ans += 1LL * common * costBoth;
            need1 -= common;
            need2 -= common;
            ans += 1LL * need1 * min(cost1, costBoth);
            ans += 1LL * need2 * min(cost2, costBoth);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna