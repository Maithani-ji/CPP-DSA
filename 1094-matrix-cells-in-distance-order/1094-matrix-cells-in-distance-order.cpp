class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rc, int cc) {
        vector<vector<int>> a;  // Create a vector to store cell coordinates sorted by distance.
       

        // Generate cell coordinates for the entire matrix.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                a.push_back({i, j});  // Add each cell's coordinates to the vector.
            }
        }

        // Sort the cells based on their Manhattan distance to the target cell (rc, cc).
        sort(a.begin(), a.end(), [rc, cc](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - rc) + abs(a[1] - cc) < abs(b[0] - rc) + abs(b[1] - cc);
        });

        return a;  // Return the vector of cell coordinates sorted by distance.
    }
};
