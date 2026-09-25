class Solution {
public:
    int countOdds(int low, int high) {
        if((high-low+1)%2==0){
            return (high-low+1)/2;
        }
        else if(low%2==0){
            return ((high-low+1)/2);
        }
        else if(low%2!=0){
            return ((high-low+1)/2)+1;
        }
        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna