class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = ""; // Initialize the title string

        while (columnNumber > 0) { // Continue loop until columnNumber becomes 0
            columnNumber--; // Keep it 0-based (no need to adjust for 1-based indexing)
            char ch = 'A' + columnNumber % 26; // Calculate the corresponding letter
            title = ch + title; // Add the letter to the beginning of the title
            columnNumber /= 26; // Move to the next digit
        }

        return title; // Return the final Excel column title
    }
};
