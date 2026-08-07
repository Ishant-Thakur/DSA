class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(char x : s){
            if(x=='('|| x=='['|| x=='{'){
                a.push(x);
            }
            else if(x==')'){
                if(a.empty()){
                    return false;
                }
                else if(a.top()=='('){
                    a.pop();
                }
                else{
                    return false;
                }
            }
            else if(x=='}'){
                if(a.empty()){
                    return false;
                }
                else if(a.top()=='{'){
                    a.pop();
                }
                else{
                    return false;
                }
            }
            else if(x==']'){
                if(a.empty()){
                    return false;
                }
                else if(a.top()=='['){
                    a.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(a.empty()){
            return true;
        }
        else{
            return false;
        }

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna