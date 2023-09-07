// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         // Create two arrays of size 26 to store character counts for 'a' to 'z'
//         int ss[26] = {0}; // Array for string s
//         int tt[26] = {0}; // Array for string t

//         // Loop through string s and increment character counts in ss
//         for (auto c : s) {
//             ss[c - 'a']++; // Increment the count for the character c
//         }

//         // Loop through string t and increment character counts in tt
//         for (auto c : t) {
//             tt[c - 'a']++; // Increment the count for the character c
//         }

//         // Compare character counts in ss and tt
//         for (int i = 0; i < 26; i++) {
//             if (ss[i] != tt[i]) {
//                 return false; // If counts differ, return false (not anagrams)
//             }
//         }

//         return true; // If counts match for all characters, return true (anagrams)
//     }
// };
class Solution {
public:
    bool isAnagram(string s, string t) {
        // Initialize an array 'count' to store the frequency of characters (26 letters)
        int count[26] = {0};
        
        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++; // Increment the count for the character 'x'
        }
        
        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--; // Decrement the count for the character 'x'
        }
        
        // Check if any character has a non-zero frequency (indicating a mismatch)
        for (int val : count) {
            if (val != 0) {
                return false; // Return false if a character count is non-zero
            }
        }
        
        return true; // If all character counts are zero, strings are anagrams
    }
};