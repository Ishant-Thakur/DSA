class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }
            if (high < 0)
                return false;
            if (low < 0)
                low = 0;
        }
        return low == 0;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna