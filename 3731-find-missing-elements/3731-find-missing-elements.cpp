class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l1 = 0;
        int l2 = mn;
        while(l1<n){
            if(nums[l1]!=l2){
                result.push_back(l2);
                l2++;
            }
            else{
                l1++;
                l2++;
            }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna