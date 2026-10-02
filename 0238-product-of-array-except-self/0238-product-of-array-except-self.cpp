class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int a = 1;
        int b = 1;
        for(int i = 0; i<n ; i++){
            ans.push_back(a);
            a*=nums[i];
        }
        for(int i = n-1;i>=0;i--){
            ans[i] *= b;
            b *= nums[i];
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna