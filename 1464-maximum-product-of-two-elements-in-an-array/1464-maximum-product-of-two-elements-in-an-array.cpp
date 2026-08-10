class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int b = 0;
        for(int i = 0 ; i<n ; i++){
            if(nums[i]>=a){
                b=a;
                a=nums[i];
            }
            else if(nums[i]>b){
                b=nums[i];
            }
        }
        return (a-1)*(b-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna