class Solution {
public:
    string removeDuplicateLetters(string s) {
       
        vector<int> freq(26, 0);  // Frequency array to count character occurrences
        vector<bool> seen(26, false);  // Array to track if character has been seen

        string res;  // Resultant string containing the smallest subsequence

        // Count the frequency of each character
        for (auto c : s) {
            freq[c - 'a']++;
        }

        // Process each character in the input string
        for (auto c : s) {
            freq[c - 'a']--;  // Decrement frequency of the current character

            // If character has already been included in the result, skip it
            if (seen[c - 'a']) {
                continue;
            }

            // Remove characters from the result string if a smaller character
            // can be added later and if it's still available in the input string
            while (!res.empty() && res.back() > c && freq[res.back() - 'a'] > 0) {
                seen[res.back() - 'a'] = false;  // Mark the character as not seen
                res.pop_back();  // Remove the character from the result
            }

            // Add the current character to the result and mark it as seen
            res.push_back(c);
            seen[c - 'a'] = true;
        }

        return res;  // Return the smallest subsequence

    }
};