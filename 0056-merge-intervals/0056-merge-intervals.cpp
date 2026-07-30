class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i<intervals.size()-1){
            vector<int> a  = intervals[i];
            vector<int> b = intervals[i+1];
            if(a[1]>=b[0]){
                if(a[1]>b[1]){
                    vector<int> c = {a[0],a[1]};
                    intervals[i]=c;
                    intervals.erase(intervals.begin() + i+1);
                }
                else{
                    vector<int> c = {a[0],b[1]};
                    intervals[i]=c;
                    intervals.erase(intervals.begin() + i+1);
                }
            }
            else{
                i++;
            }
        }
        return intervals;

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna