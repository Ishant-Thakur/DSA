class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int same = 1;

            for (int j = i + 1; j < n; j++) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;
                    continue;
                }

                double slope;

                if (dx == 0)
                    slope = 1e9;
                else
                    slope = (double)dy / dx;

                mp[slope]++;
            }

            ans = max(ans, same);

            for (auto it : mp) {
                ans = max(ans, it.second + same);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna