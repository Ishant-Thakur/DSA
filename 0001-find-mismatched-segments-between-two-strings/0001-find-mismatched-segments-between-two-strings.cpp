class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        int n = s1.size();
        int i = 0;
        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            }
            int start = i;
            string sub1 = "";
            string sub2 = "";
            while(i<n&&s1[i]!=s2[i]){
                sub1+=s1[i];
                sub2+= s2[i];
                i++;
            }
            ans.push_back({sub1,sub2});
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna