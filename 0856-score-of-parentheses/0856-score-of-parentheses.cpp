class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(auto x : s){
            if(x=='('){
                st.push(0);
            }
            else{
                int a = st.top();
                st.pop();
                int score ;
                if(a==0)
                    score = 1;
                else
                    score = 2*a;
                st.top()+=score;
            }
        }
        return st.top();
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna