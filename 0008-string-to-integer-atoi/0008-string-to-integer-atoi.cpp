class Solution {
public:
    int myAtoi(string s) {
        int a = 0;
        int sign = 1;
        int i = 0;
        while(s.length() > 0 && s[0] == ' ') {
        s.erase(0,1);
        }
        if(s[0]=='-'){
            sign=-1;
            i =1;
            }
        if(s[0]=='+'){
            i=1;
        }
        for(i;i<s.length();i++){
            if((s[i]-'0')>=0&&(s[i]-'0')<=9){
                int digit = s[i] - '0';
                if(a > INT_MAX/10 || (a == INT_MAX/10 && digit > 7)){
                 return sign == 1 ? INT_MAX : INT_MIN;
                }
                a=(a*10)+(s[i]-'0');
            }
            else{
                break;
            }
            
        }
        a=a*sign;
        return a; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna