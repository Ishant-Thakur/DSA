class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int x : nums)freq[x]++;
        for(int x : target)freq[x]--;
        for(auto &p : freq){
            if(p.second != 0)return 0;
        }
        vector<bool>suffix(n,true);
        for(int i = n-2;i>=0;i--){
            suffix[i]=suffix[i+1]&&(target[i]>= target[i+1]);
        }
        int ans = 0;
        bool prefixmatch = true;
        for(int i = 0;i<n;i++){
            if(prefixmatch && suffix[i]){
                ans++;
            }
            if(nums[i]!=target[i]){
                prefixmatch = false;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna