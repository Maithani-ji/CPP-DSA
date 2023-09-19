class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') { // Check for empty cell
                    for (char c = '1'; c <= '9'; c++) { // Try placing digits 1 to 9
                        if (isSafe(c, i, j, board)) { // Check if it's safe to place 'c'
                            board[i][j] = c; // Place 'c' in the current cell
                            if (solve(board)) { // Recursively solve the board
                                return true; // If a solution is found, return true
                            } else {
                                board[i][j] = '.'; // Backtrack if the solution is not found
                            }
                        }
                    }
                    return false; // No valid digit found, backtrack
                }
            }
        }
        return true; // The Sudoku board is solved
    }

    bool isSafe(char c, int row, int col, vector<vector<char>>& board) {
        // Check row, column, and subgrid for the presence of 'c'
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c || board[i][col] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false; // 'c' is already present in the row, column, or subgrid
            }
        }
        return true; // 'c' is safe to place in the current cell
    }
};
