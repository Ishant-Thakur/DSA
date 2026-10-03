class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> a;
        a.push(-1);
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                a.push(i);
            }
            else{
                a.pop();
                if(a.empty()){
                    a.push(i);
                }
                else{
                    int length = i - a.top();
                    ans = max(ans, length);
                }
            }
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna