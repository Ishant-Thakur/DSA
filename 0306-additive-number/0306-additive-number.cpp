class Solution {
public:
     string addStrings(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans += char(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool solve(string a, string b, string remaining) {

        if (remaining.empty()) {
            return true;
        }

        string sum = addStrings(a, b);

        if (remaining.find(sum) != 0) {
            return false;
        }

        return solve(b, sum, remaining.substr(sum.size()));
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {

            string a = num.substr(0, i);

            if (a.size() > 1 && a[0] == '0')
                break;

            for (int j = 1; max(i, j) <= n - i - j; j++) {

                string b = num.substr(i, j);

                if (b.size() > 1 && b[0] == '0')
                    break;

                string remaining = num.substr(i + j);

                if (solve(a, b, remaining)) {
                    return true;
                }
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna