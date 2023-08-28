class Solution {
public:
    int addMinimum(string word) {
        int ans = 0, i = 0; // Initialize ans (answer) to keep track of additions needed, and i to iterate through the characters
        
        // Loop through the characters in the word
        while (i < word.size()) {
            // If the current character is 'a', increment i to skip this character
            // If it's not 'a', increment ans since we need to add a character to form a valid "abc" chunk
            (word[i] == 'a') ? i++ : ans++;
            
            // Similar logic for 'b'
            (word[i] == 'b') ? i++ : ans++;
            
            // Similar logic for 'c'
            (word[i] == 'c') ? i++ : ans++;
        }
        
        return ans; // Return the minimum number of additions needed
    }
};
