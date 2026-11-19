class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        // End word must exist in dictionary
        if (st.find(endWord) == st.end()) {
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;

            q.pop();

            // We reached the destination
            if (word == endWord) {
                return steps;
            }

            // Try changing every character
            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // Check if generated word exists
                    if (st.find(word) != st.end()) {

                        q.push({word, steps + 1});

                        // Mark as visited
                        st.erase(word);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna