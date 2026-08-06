class Solution{
public:
    int smallestNumber(int n, int t){
        if (n % 10 == 0)
        {
            return n;
        }
        else
        {
            while (true)
            {
                int b = n;
                int first;
                int second = -1;
                if (b >= 10)
                {
                    first = b % 10;
                    b /= 10;
                    second = b % 10;
                }
                else
                {
                    first = b % 10;
                }
                if (second != -1)
                {
                    int product = first * second;
                    if (product % t == 0)
                    {
                        return n;
                    }
                    else
                    {
                        n++;
                        
                    }
                }
                else
                {
                    if (n % t == 0)
                    {
                        return n;
                    }
                    else
                    {
                        n++;
                        
                    }
                }
            }
            return 0;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna