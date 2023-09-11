class Solution {
public:
    vector<vector<int>> ans; // Vector to store the resulting combinations

    // Recursive function to generate combinations
    void generate(int k, int n, vector<int>& v, int i, int j, int sum) {
       

        if (i == k && sum == n) {
            ans.push_back(v); // If we've generated a valid combination, add it to the result
            return;
        }

        if (sum > n || j>9 || i > k) {
            return; // If the sum exceeds the target, j goes beyond 9, or i exceeds k, return without generating further combinations
        }

        // Include the current number j in the combination
        v.push_back(j);
        generate(k, n, v, i + 1, j + 1, sum + j); // Recursively generate combinations with the current number

        // Backtrack: Remove the last added element
        v.pop_back();

        // Generate combinations without the current number j
        generate(k, n, v, i, j+1, sum); // Recursively generate combinations without the current number
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v; // Temporary vector to hold the current combination being built
        generate(k, n, v, 0, 1, 0); // Start generating combinations with i=0, j=1, and sum=0
        return ans; // Return the resulting combinations
    }
};

