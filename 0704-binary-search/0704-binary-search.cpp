class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(right>=left){
            int mid = (left+right)/2;
            if(nums[mid]>target){
                right = mid - 1;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna