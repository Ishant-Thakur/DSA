class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;
        int sum ;
        while(right>left){
            sum = numbers[left]+numbers[right];
            if(sum>target){
                right--;
            }
            else if(sum<target){
                left++;
            }
            else{
                break;
            }
        }
        return {left+1,right+1};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna