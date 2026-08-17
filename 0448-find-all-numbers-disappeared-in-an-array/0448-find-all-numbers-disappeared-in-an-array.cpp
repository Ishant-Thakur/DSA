class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result ;
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        for(int i = 1 ; i<=n ; i++){
            if(s.find(i)==s.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna