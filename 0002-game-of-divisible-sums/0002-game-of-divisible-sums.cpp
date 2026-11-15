class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n =nums.size();
        vector<long long> dp(n+1,0);
        for(int i =n-1 ;i>= 0 ; --i){
            long long s1 = nums[i];
            long long opt1 = (s1%3==0)? (s1-dp[i+1]):(s1+dp[i+1]);
            if(i+1<n){
                long long s2 = (long long)nums[i] + nums[i+1];
                long long opt2 = (s2%3==0)? (s2 - dp[i+2]) : (s2+ dp[i+2]);
                dp[i]=max(opt1,opt2);
            }
            else{
                dp[i]=opt1;
            }
        }
        return dp[0];
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna