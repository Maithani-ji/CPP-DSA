class Solution {
public:
    vector<string> ans; // Vector to store the resulting letter case permutations

    void generate(string s, int i) {
        if (i == s.size()) {   
            // If we have processed the entire string, add the permutation to ans
            ans.push_back(s);
            return ;
        }

        if (isdigit(s[i])) {
            // If the character at index i is a digit, move to the next index
            generate(s, i + 1);
        } else {
            // If the character at index i is a letter (alphabet character)
            // Explore both uppercase and lowercase variations of the letter

            // Convert the letter to uppercase and explore
            s[i] = toupper(s[i]);
            generate(s, i + 1);

            // Convert the letter to lowercase and explore
            s[i] = tolower(s[i]);
            generate(s, i + 1);

            // Restore the character to its original case for backtracking
            s[i] = toupper(s[i]);
        }
    }

    vector<string> letterCasePermutation(string s) {
        generate(s, 0); // Start generating permutations from index 0
        return ans;    // Return the vector containing all letter case permutations
    }
};
