class Solution {
public:
    string removeStars(string s) {
        stack<char> a;
        string ans;
        for(char x : s){
            if(x!='*'){
                a.push(x);
            }
            else{
                a.pop();
            }
        }
        while(!a.empty()){
            ans+=a.top();
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna