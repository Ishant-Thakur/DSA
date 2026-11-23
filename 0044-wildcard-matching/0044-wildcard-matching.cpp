class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;

        int star = -1;
        int match = 0;

        while (i < s.length()) {

            // Characters match or pattern has '?'
            if (j < p.length() &&
                (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }

            // Found '*', remember its position
            else if (j < p.length() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }

            // Previous '*' can match one more character
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }

            // No possible match
            else {
                return false;
            }
        }

        // Skip remaining '*' characters
        while (j < p.length() && p[j] == '*') {
            j++;
        }

        return j == p.length();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna