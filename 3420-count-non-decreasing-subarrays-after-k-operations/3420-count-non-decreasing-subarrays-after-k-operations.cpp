class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<int> nxt(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nxt[i] = st.top();
            }
            st.push(i);
        }
        vector<vector<int>> up(LOG, vector<int>(n, n));
        vector<vector<long long>> sum(
            LOG, vector<long long>(n, 0)
        );
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];
                if (mid != n) {
                    up[j][i] = up[j - 1][mid];
                    sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
                } else {
                    up[j][i] = n;
                    sum[j][i] = sum[j - 1][i];
                }
            }
        }
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        auto getMaxSum = [&](int l, int r) {
            long long res = 0;
            int cur = l;
            for (int j = LOG - 1; j >= 0; j--) {
                int next = up[j][cur];
                if (next <= r + 1) {
                    res += sum[j][cur];
                    cur = next;
                    if (cur == n) break;
                }
            }
            if (cur <= r) {
                res += 1LL * nums[cur] * (r - cur + 1);
            }
            return res;
        };
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int lo = 0, hi = r;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                long long operations =
                    getMaxSum(mid, r) -
                    (pref[r + 1] - pref[mid]);
                if (operations <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            ans += (r - lo + 1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna