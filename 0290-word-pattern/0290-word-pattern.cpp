
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Initialize two unordered maps to store mappings between characters and words
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        // Create a stringstream to tokenize the input string 's'
        istringstream iss(s);
        string word;
        int i = 0; // Initialize the index for 'pattern'

        while (iss >> word) {
            // If there are more words in 's' than characters in 'pattern', return false
            if (i == pattern.size()) {
                return false;
            }

            char c = pattern[i]; // Get the current character from 'pattern'

            // Check if the current character-to-word mapping exists and is consistent
            if (charToWord.find(c) != charToWord.end() && charToWord[c] != word) {
                return false;
            }

            // Check if the current word-to-character mapping exists and is consistent
            if (wordToChar.find(word) != wordToChar.end() && wordToChar[word] != c) {
                return false;
            }

            // Update the character-to-word and word-to-character mappings
            charToWord[c] = word;
            wordToChar[word] = c;
            i++; // Move to the next character in 'pattern'
        }

        // Ensure both 'pattern' and 's' are fully processed (i.e., no leftover characters or words)
        return i == pattern.size();
    }
};
