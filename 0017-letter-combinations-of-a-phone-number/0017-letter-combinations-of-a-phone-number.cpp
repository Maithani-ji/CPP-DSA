class Solution {
public:
    vector<string> ans; // Vector to store letter combinations
    
    // Recursive function to generate letter combinations
    void generate(vector<string>& mp, string v, int nums) {
        if (nums == 0) {   
            ans.push_back(v); // If nums becomes 0, add the current combination to ans
            return;
        }

        int x = nums % 10; // Extract the last digit
        string s = mp[x]; // Get the corresponding letters for the digit
        for (auto c : s) {
            generate(mp, c + v, nums / 10); // Recursively generate combinations for the remaining digits
        }
    }
    
    // Function to generate letter combinations from a numeric string
    vector<string> letterCombinations(string num) {
        for (char c : num) {
            if (!isdigit(c)) {
                return ans; // Return an empty result vector if the input contains non-numeric characters
            }
        }

        if (num.empty()) {
            return ans; // Return an empty result vector if the input is empty
        }
        
        int nums = stoi(num); // Convert the input string to an integer
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // Mapping of digits to letters
        generate(mp, "", nums); // Generate letter combinations using recursion
        return ans; // Return the generated letter combinations
    }
};
