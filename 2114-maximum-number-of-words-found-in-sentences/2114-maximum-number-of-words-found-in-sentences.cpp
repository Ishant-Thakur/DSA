class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=1;
        for(string s : sentences){
            int b = 1;
            for(int i = 0 ; i<s.size(); i++){
                if(s[i]==' '){
                    b++;
                }

            }
            ans = max(ans,b);
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna