class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans =0;
        int mid = n/2;
        for(int x : nums){
            if(x<nums[mid]){
                ans = ans +(nums[mid]-x);
            }
            else if(x==nums[mid]){
                ans  = ans + 0;
            }
            else{
                ans = ans+(x-nums[mid]);
            }
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna