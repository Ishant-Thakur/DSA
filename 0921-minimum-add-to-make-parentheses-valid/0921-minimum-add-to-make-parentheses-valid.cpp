class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto x : s ){
            if(x=='('){
                st.push(x);
            }
            else{
                if(st.empty()){
                    st.push(x);
                }
                else if(st.top()=='('&&!st.empty()){
                    st.pop();
                }
                else{
                    st.push(x);
                }
            }
        }
        return st.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna