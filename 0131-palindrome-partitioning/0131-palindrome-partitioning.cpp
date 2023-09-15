class Solution {
public:
    vector<vector<string>> ans; // Vector to store the result
    vector<string> v; // Vector to store the current combination

    // Helper function to check if a string is a palindrome
    bool ispal(string ss) {
        int i = 0;
        int j = ss.size() - 1;
        while (i < j) {
            if (ss[i] == ss[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    // Recursive function to generate palindromic partitions
    void generate(string s, int i) {
        if (i == s.size()) { // If the current index reaches the end of the string
            ans.push_back(v); // Add the current combination to the result
            return; // Return to backtrack and explore other combinations
        }
        
        string ss = ""; // Initialize an empty string

        for (int j = i; j < s.size(); j++) { // Iterate through the string starting from the current index
            ss += s[j]; // Add the current character to the temporary string
            if (ispal(ss)) { // If the temporary string is a palindrome
                v.push_back(ss); // Add it to the current combination
                generate(s, j + 1); // Recursively generate partitions for the remaining substring
                v.pop_back(); // Backtrack by removing the last added string (restoring the previous state)
            }
        }
    }

    // Function to generate all palindromic partitions of a string
    vector<vector<string>> partition(string s) {
        generate(s, 0); // Start generating partitions from index 0
        return ans; // Return the result vector containing all partitions
    }
};
