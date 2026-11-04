class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
         int n = nums.size();
        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } 
            else {
                right.insert(val);
                sumRight += val;
            }
        };
        auto remove = [&](int val) {
            auto it = left.find(val);
            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } 
            else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }
        };
        auto balance = [&]() {
            int total = left.size() + right.size();
            int target = (total + 1) / 2;
            while (left.size() > target) {
                auto it = prev(left.end());
                int val = *it;
                left.erase(it);
                sumLeft -= val;
                right.insert(val);
                sumRight += val;
            }
            while (left.size() < target) {
                auto it = right.begin();
                int val = *it;
                right.erase(it);
                sumRight -= val;
                left.insert(val);
                sumLeft += val;
            }
        };
        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();
            return median * left.size() - sumLeft + sumRight - median * right.size();
        };
        vector<long long> cost;
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                balance();
                cost.push_back(getCost());
            }
        }
        const long long INF = 1e18;
        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                long long skip = dp[i + 1][j];
                long long take = INF;
                if (i + x <= n && dp[i + x][j - 1] != INF) {
                    take = cost[i] + dp[i + x][j - 1];
                }
                dp[i][j] = min(skip, take);
            }
        }
        return dp[0][k];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna