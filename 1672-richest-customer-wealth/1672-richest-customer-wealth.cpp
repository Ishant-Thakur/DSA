class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0;
        for(vector<int> x : accounts){
            vector<int> a = x;
            int b = 0;
            for(int y : a){
                b += y;
            }
            sum = max(sum,b);
        }
        return sum;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna