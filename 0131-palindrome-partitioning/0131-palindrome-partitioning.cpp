class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string &s, int index) {

        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            if (isPalindrome(s, index, i)) {

                temp.push_back(s.substr(index, i - index + 1));

                solve(s, i + 1);

                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna