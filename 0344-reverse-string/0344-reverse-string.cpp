class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0 ; i<n/2; i++){
            swap(s[i],s[n-1-i]);
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna