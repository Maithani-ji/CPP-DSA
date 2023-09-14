class Solution {//using combination sum or subset algo , with just size of combination is given ie k
public:
    vector<vector<int>> ans; // Vector to store combinations
    vector<int> v; // Vector to store the current combination

    // Recursive function to generate combinations
    void generate(int n, int k, int i) {
        if (v.size() == k) { // If the current combination has reached the desired size (k)
            ans.push_back(v); // Add the current combination to the result vector
            return; // Return to backtrack and explore other combinations
        }
        if (i > n || v.size() > k) {
            return; // If we have exceeded the maximum value or the desired combination size, return
        }

        v.push_back(i); // Include the current value in the combination
        generate(n, k, i + 1); // Recursively generate combinations with the current value included
        v.pop_back(); // Backtrack by removing the current value from the combination
        generate(n, k, i + 1); // Recursively generate combinations with the current value excluded
    }

    // Function to generate all combinations of k elements from the numbers 1 to n
    vector<vector<int>> combine(int n, int k) {
        generate(n, k, 1); // Start generating combinations with the first value (1)
        return ans; // Return the result vector containing all combinations
    }
};
