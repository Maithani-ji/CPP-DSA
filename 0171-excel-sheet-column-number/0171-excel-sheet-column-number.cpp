class Solution {
public:
    int titleToNumber(string s) {
        long long res = 0; // Initialize the result variable to store the column number.
        
        // Iterate through each character in the input string.
        for (auto c : s) {
            // Calculate the column number using the formula: res = res * 26 + (c - 'A' + 1).
            // 'A' is subtracted to convert the character to a zero-based index (A=0, B=1, ..., Z=25).
            // Adding 1 adjusts the index to be one-based (A=1, B=2, ..., Z=26).
            res = res * 26 + c - 'A' + 1;
        }
        
        return (int)res; // Return the final calculated column number.
    }
};
