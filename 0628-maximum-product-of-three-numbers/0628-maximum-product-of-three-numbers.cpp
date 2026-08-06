class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int l3 = INT_MIN;
        int s1= INT_MAX;
        int s2= INT_MAX;
        for(int x : nums){
            if(x>l1){
                l3 = l2;
                l2=l1;
                l1 = x;
            }
            else if(x>l2){
                l3=l2;
                l2 = x;
            }
            else{
                if(x>l3)
                    l3 = x;
            }
            if(x<s1){
                s2=s1;
                s1=x;
            }
            else{
                if(x<s2)
                    s2=x;
            }
        }
        int ans1 = l1*l2*l3;
        int ans2 = s1*s2*l1;
        result = max(ans1,ans2);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna