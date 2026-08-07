class Solution {
public:

    // prime factors of digits 0..9
    // order: 2, 3, 5, 7
    vector<vector<int>> factors = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    // Convert required prime factors into the
    // minimum number of digits 2..9.
    vector<int> getDigits(vector<int> cnt) {

        vector<int> digitCount(10, 0);

        // 2^3 = 8
        digitCount[8] = cnt[0] / 3;
        cnt[0] %= 3;

        // 3^2 = 9
        digitCount[9] = cnt[1] / 2;
        cnt[1] %= 2;

        // 2^2 = 4
        digitCount[4] = cnt[0] / 2;
        cnt[0] %= 2;

        // If we have one 2 and one 3, make a 6
        if (cnt[0] == 1 && cnt[1] == 1) {
            digitCount[6] = 1;
            cnt[0] = 0;
            cnt[1] = 0;
        }

        // Special case: one 3 and one 4
        if (cnt[1] == 1 && digitCount[4] == 1) {
            digitCount[4] = 0;
            digitCount[6] = 1;
            digitCount[2] = 1;
            cnt[1] = 0;
        }

        digitCount[2] += cnt[0];
        digitCount[3] += cnt[1];

        digitCount[5] = cnt[2];
        digitCount[7] = cnt[3];

        return digitCount;
    }

    string buildNumber(vector<int> digitCount) {
        string ans;

        // Increasing order gives the smallest number
        for (int d = 2; d <= 9; d++) {
            ans += string(digitCount[d], char('0' + d));
        }

        return ans;
    }

    int countDigits(vector<int> digitCount) {
        int total = 0;

        for (int d = 2; d <= 9; d++)
            total += digitCount[d];

        return total;
    }

    string smallestNumber(string num, long long t) {

        // --------------------------------------------------
        // STEP 1: Factorize t
        // --------------------------------------------------

        vector<int> need(4, 0);

        int primes[] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {

            while (t % primes[i] == 0) {
                need[i]++;
                t /= primes[i];
            }
        }

        // If anything is left, t has a prime factor
        // other than 2,3,5,7 -> impossible.
        if (t != 1)
            return "-1";


        // --------------------------------------------------
        // STEP 2: Find minimum number of digits needed
        // --------------------------------------------------

        vector<int> minDigits = getDigits(need);

        int requiredLength = countDigits(minDigits);

        // If we need more digits than num has,
        // the answer must have one more/more digits.
        if (requiredLength > num.size()) {
            return buildNumber(minDigits);
        }


        // --------------------------------------------------
        // STEP 3: Count prime factors in num
        // --------------------------------------------------

        vector<int> totalFactors(4, 0);

        for (char c : num) {

            int d = c - '0';

            for (int j = 0; j < 4; j++)
                totalFactors[j] += factors[d][j];
        }


        // --------------------------------------------------
        // STEP 4: num itself may already be the answer
        // --------------------------------------------------

        bool hasZero = false;

        for (char c : num) {
            if (c == '0') {
                hasZero = true;
                break;
            }
        }

        bool enoughFactors = true;

        for (int j = 0; j < 4; j++) {
            if (totalFactors[j] < need[j])
                enoughFactors = false;
        }

        if (!hasZero && enoughFactors)
            return num;


        // --------------------------------------------------
        // STEP 5: Try changing a digit from right to left
        // --------------------------------------------------

        vector<int> prefix = totalFactors;

        int firstZero = num.find('0');

        if (firstZero == string::npos)
            firstZero = num.size();


        for (int i = num.size() - 1; i >= 0; i--) {

            int currentDigit = num[i] - '0';

            // Remove current digit from prefix
            for (int j = 0; j < 4; j++) {
                prefix[j] -= factors[currentDigit][j];
            }

            // If there is a zero after this position,
            // we cannot keep this prefix.
            if (i > firstZero)
                continue;


            // Try the smallest digit greater than current digit
            for (int bigger = currentDigit + 1;
                 bigger <= 9;
                 bigger++) {

                vector<int> remaining(4);

                for (int j = 0; j < 4; j++) {

                    remaining[j] =
                        max(0,
                            need[j]
                            - prefix[j]
                            - factors[bigger][j]);
                }


                // Find minimum digits required for the suffix
                vector<int> suffixDigits = getDigits(remaining);

                int suffixLength = countDigits(suffixDigits);

                int available = num.size() - i - 1;

                if (suffixLength <= available) {

                    string ans = num.substr(0, i);

                    // Put the larger digit here
                    ans += char('0' + bigger);

                    // Fill unused positions with 1
                    ans += string(available - suffixLength, '1');

                    // Put required digits at the end
                    ans += buildNumber(suffixDigits);

                    return ans;
                }
            }
        }


        // --------------------------------------------------
        // STEP 6: No answer with same length.
        // Make a number with one extra digit.
        // --------------------------------------------------

        vector<int> finalDigits = getDigits(need);

        int len = countDigits(finalDigits);

        string ans;

        // Extra 1's make the number longer than num
        ans += string(num.size() + 1 - len, '1');

        ans += buildNumber(finalDigits);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna