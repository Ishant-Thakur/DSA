class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();
        int a = min(minidx, maxidx);
        int b = max(minidx, maxidx);
        int fromfront = b + 1;
        int fromback = n - a;
        int bothEnds = (a + 1) + (n - b);
        return min({fromfront, fromback, bothEnds});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna