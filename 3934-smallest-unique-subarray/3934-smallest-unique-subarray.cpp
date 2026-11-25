class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> rank(n), sa(n), temp(n);

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i])
                      - vals.begin();
            sa[i] = i;
        }

        // Build suffix array using doubling
        for (int k = 1; k < n; k *= 2) {
            vector<pair<pair<int,int>,int>> v(n);

            for (int i = 0; i < n; i++) {
                v[i] = {{rank[i],
                         i + k < n ? rank[i + k] : -1}, i};
            }

            sort(v.begin(), v.end());

            for (int i = 0; i < n; i++) {
                sa[i] = v[i].second;
            }

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] +
                    (v[i].first != v[i - 1].first);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP array using Kasai's algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        // Find minimum unique subarray length
        int ans = n;

        for (int r = 0; r < n; r++) {
            int common = lcp[r];

            if (r + 1 < n) {
                common = max(common, lcp[r + 1]);
            }

            int start = sa[r];

            if (common < n - start) {
                ans = min(ans, common + 1);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna