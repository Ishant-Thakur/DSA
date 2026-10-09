class Solution {
public:
    int minInsertions(string s) {
        int need = 0, ans = 0;
        for(char x : s){
            if(x=='('){
                if(need%2!=0){
                    ans++;
                    need--;
                }    
                need+=2;
            }
            else{
                if(need>0){
                    need--;
                }
                else if(need==0){
                    ans++;
                    need=1;
                }
            }
            
        }

        return ans + need ;
    }

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna