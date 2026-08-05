class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        if(n==3){
            result = nums[0]*nums[1]*nums[2];
        }
        else{
            sort(nums.begin(),nums.end());
            int ans1 = nums[0]*nums[1]*nums[n-1];
            int ans2 = nums[n-1]*nums[n-2]*nums[n-3];
            result = max(ans1,ans2);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna