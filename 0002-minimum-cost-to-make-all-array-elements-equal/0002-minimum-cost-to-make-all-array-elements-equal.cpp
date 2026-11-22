class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        int i =0;
        while(i<n){
            int j =i;
            while(j+1<n&&nums[j]==nums[j+1]){
                j++;
            }
            if(i==0 && j==n-1){
                return 0;
            }
            if(max(i,1)<=min(j,n-2)){
                long long cost = (1LL*i+n-1-j)*nums[i];
                ans = min(ans,cost);
            }
            i=j+1;
        }
        return ans == LLONG_MAX ? -1 : ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna