class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int sum = 0;
        vector<int> ans ;
        for(int x : nums){
            int count = 0 ;
            for(int y : nums){
                if(x>y)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna