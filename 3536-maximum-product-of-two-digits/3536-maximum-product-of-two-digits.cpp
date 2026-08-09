class Solution {
public:
    int maxProduct(int n) {
        int f = 0, s = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (digit >= f) {
                s = f;
                f = digit;
            } 
            else if (digit > s) {
                s = digit;
            }
        }
        return f*s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna