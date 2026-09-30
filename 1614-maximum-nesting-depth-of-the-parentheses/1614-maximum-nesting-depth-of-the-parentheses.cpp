class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        stack<char> a;
        for(char x : s){
            if(x=='('){
                a.push(x);
                count++;
            }
            else if (x==')'){
                a.pop();
                ans = max(ans,count);
                count--;
            }
        }
        return ans;   
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna