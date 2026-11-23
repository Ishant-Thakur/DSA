class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currRow = 0;
        int direction = 1; // 1 = down, -1 = up

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0)
                direction = 1;
            else if (currRow == numRows - 1)
                direction = -1;

            currRow += direction;
        }

        string result;

        for (string row : rows) {
            result += row;
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna