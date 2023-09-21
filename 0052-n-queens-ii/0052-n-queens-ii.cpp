class Solution {
public:
    int count = 0; // Variable to store the count of valid solutions
    
    // Recursive function to solve the N-Queens problem
    void solve(vector<string> board, int n, vector<int> left, vector<int> udiag, vector<int> ldiag, int col) {
        // If all queens are placed, increment the solution count and return
        if (col == n) {
            count++;
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (left[row] == 0 && udiag[n - 1 + (col - row)] == 0 && ldiag[row + col] == 0) {
                // If it's safe to place a queen in this cell, mark it and update availability vectors
                board[row][col] = 'Q';
                left[row] = 1;
                udiag[n - 1 + (col - row)] = 1;
                ldiag[row + col] = 1;

                // Recursively proceed to the next column
                solve(board, n, left, udiag, ldiag, col + 1);

                // Backtrack by resetting the cell and availability vectors to explore other possibilities
                board[row][col] = '.';
                left[row] = 0;
                udiag[n - 1 + (col - row)] = 0;
                ldiag[row + col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.')); // Initialize the chessboard
        vector<int> left(n, 0); // Availability vector for columns
        vector<int> udiag(2 * n - 1, 0); // Availability vector for upper diagonals
        vector<int> ldiag(2 * n - 1, 0); // Availability vector for lower diagonals

        solve(board, n, left, udiag, ldiag, 0); // Start solving from the first column
        return count; // Return the count of valid solutions
    }
};

/*class Solution {// Brute force--> checking IS SAFE TO put queen , seperately. 
public:
int c=0;
     int totalNQueens(int n) {
     //   vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize an empty chessboard

        solve(board, solutions, 0, n); // Start the solving process

      //  return solutions;
      return c;
    }

    // Recursive function to solve N-Queens problem
    void solve(vector<string>& board, vector<vector<string>>& solutions, int row, int n) {
        if (row == n) {
            // If we have placed all queens successfully, add the solution to the result
           // solutions.push_back(board);
           c++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q'; // Place a queen

                // Recursively try to place queens in the next row
                solve(board, solutions, row + 1, n);

                board[row][col] = '.'; // Backtrack by removing the queen
            }
        }
    }

    // Helper function to check if it's safe to place a queen at a specific position
    bool isSafe(const vector<string>& board, int row, int col, int n) {
        // Check the same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
*/