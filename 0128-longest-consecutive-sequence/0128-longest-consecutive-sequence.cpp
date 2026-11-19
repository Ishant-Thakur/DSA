class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int count = 1;
                int curr = num;
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna