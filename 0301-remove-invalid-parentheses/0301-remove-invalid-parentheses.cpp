class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        
        int leftRemove = 0;
        int rightRemove = 0;
        
        // Find how many '(' and ')' need to be removed
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }
        
        function<void(int, int, int, string)> dfs =
        [&](int index, int left, int right, string curr) {
            
            if (index == s.size()) {
                if (leftRemove == 0 && rightRemove == 0 &&
                    left == right) {
                    ans.insert(curr);
                }
                return;
            }
            
            char c = s[index];
            
            // Remove current character
            if (c == '(' && leftRemove > 0) {
                leftRemove--;
                dfs(index + 1, left, right, curr);
                leftRemove++;
            }
            
            if (c == ')' && rightRemove > 0) {
                rightRemove--;
                dfs(index + 1, left, right, curr);
                rightRemove++;
            }
            
            // Keep current character
            if (c != '(' && c != ')') {
                dfs(index + 1, left, right, curr + c);
            }
            
            else if (c == '(') {
                dfs(index + 1, left + 1, right, curr + c);
            }
            
            else if (c == ')' && left > right) {
                dfs(index + 1, left, right + 1, curr + c);
            }
        };
        
        dfs(0, 0, 0, "");
       
        return vector<string>(ans.begin(), ans.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna