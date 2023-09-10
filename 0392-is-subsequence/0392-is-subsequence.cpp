class Solution {
public:
    // Function to check if string s is a subsequence of string t
    bool isSubsequence(string s, string t) {
        // Initialize two pointers, i for string s and j for string t
        int i = 0;
        int j = 0;

        // Iterate through string t
        while (j < t.size()) {
            // Check if the current characters in s and t match
            if (s[i] == t[j]) {
                // If they match, move to the next character in s
                i++;
            }
            // Move to the next character in t
            j++;
        }

        // If i has reached the end of s, s is a subsequence of t
        if (i == s.size()) {
            return true;
        }
        // Otherwise, s is not a subsequence of t
        return false;
    }
};
