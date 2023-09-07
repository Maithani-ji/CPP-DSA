class Solution {
public:
    bool isAnagram(string s, string t) {
        // Create two arrays of size 26 to store character counts for 'a' to 'z'
        int ss[26] = {0}; // Array for string s
        int tt[26] = {0}; // Array for string t

        // Loop through string s and increment character counts in ss
        for (auto c : s) {
            ss[c - 'a']++; // Increment the count for the character c
        }

        // Loop through string t and increment character counts in tt
        for (auto c : t) {
            tt[c - 'a']++; // Increment the count for the character c
        }

        // Compare character counts in ss and tt
        for (int i = 0; i < 26; i++) {
            if (ss[i] != tt[i]) {
                return false; // If counts differ, return false (not anagrams)
            }
        }

        return true; // If counts match for all characters, return true (anagrams)
    }
};
