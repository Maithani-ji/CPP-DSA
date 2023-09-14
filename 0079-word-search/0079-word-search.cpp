class Solution {
public:
    // Recursive function to check if the word can be found on the board after finding starting 1st char in EXIST FUCN
    bool check(vector<vector<char>>& board, string word, int n, int m, int i, int j, int k) {
        // Base case: If we have found the entire word or the word has only one character, return true
        if (i == word.size() || word.size()==1) {
            return true;
        }

        // Check for out-of-bounds or mismatch conditions
        if (j < 0 || k < 0 || j >= n || k >= m || word[i] != board[j][k] || board[j][k]=='.') {
            return false;
        }

        // Temporarily mark the current cell as visited
        char temp = board[j][k];
        board[j][k] = '.';

        // Recursively explore adjacent cells
        bool found = check(board, word, n, m, i + 1, j - 1, k) ||  // Check left cell
                     check(board, word, n, m, i + 1, j + 1, k) ||  // Check right cell
                     check(board, word, n, m, i + 1, j, k + 1) ||  // Check lower cell
                     check(board, word, n, m, i + 1, j, k - 1);    // Check upper cell

        // Restore the cell's original value
        board[j][k] = temp;

        return found;
    }

    // Function to check if the word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();        // Number of rows
        int m = board[0].size();     // Number of columns

        // Iterate through the entire board
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Check if the first character of the word matches the current cell
                if (board[i][j] == word[0]) {
                    if ( check(board, word, n, m, 0, i, j)) {
                        return true;  // Word found on the board
                    }
                    
                }
            }
        }

        return false; // Word not found on the board
    }
};
