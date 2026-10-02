class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int x : nums){
            a= a^x;
        }
        return a;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna