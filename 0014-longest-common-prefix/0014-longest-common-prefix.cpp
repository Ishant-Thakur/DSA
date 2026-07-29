class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
                return "";
            }
        string check = strs[0];
        int n = strs.size();
        string end = "";
        for(int i = 1; i<n; i++){
            if(check.empty()){
                break;
            }
            string temp ="";
            string test = strs[i];
            int s1 = check.size();
            int s2 = test.size();
            int s3 = 0;
            if(s1>s2){
                s3 = s2;
            }
            else{
                s3 = s1;
            }

            for(int j = 0;j<s3; j++){
                if(check[j]==test[j]){
                    temp = temp + check[j];
                }
                else{
                    break;
                }
                
            }
            check = temp;

        }

        return check;

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna