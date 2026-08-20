class Solution {
public:
    int lengthOfLastWord(string s) {
        int result=0;
        int n = s.size();
        int i = n-1;
        while(i>=0){
            if(s[i]!=' '){
                i--;
                result++;
            }
            else{
                if(result>0){
                    break;
                }
                i--;
            }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna