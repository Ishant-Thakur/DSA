class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int ans[n*2];
        for(int i = 0;i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        vector<int> final(ans, ans + n*2);
        return final;

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna