class Solution {
public:
    int minRotations(string s) {
        int current = 0;
        int rotation =0;
        for(char c:s){
            int target = c-'0';
            int dis = abs(current - target);
            dis = min(dis,10-dis);
            rotation+=dis;
            current = target;
        }
        return rotation;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna