class Solution {// same as combination sum 2 algo without sum // recursion // brute
public:
    vector<vector<int>> ans; // Vector to store the resulting subsets

    // Recursive function to generate subsets
    void generate(int i, vector<int> nums, vector<int> v) {
        if (i == nums.size()) {
            ans.push_back(v); // If we've processed all elements, add the current subset to the result
            return;
        }

        v.push_back(nums[i]); // Include the current element in the subset
        generate(i + 1, nums, v); // Recursively generate subsets with the current element

        // Skip duplicates
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        v.pop_back(); // Backtrack by removing the last added element
        generate(i + 1, nums, v); // Recursively generate subsets without the current element
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v; // Temporary vector to hold the current subset being built
        sort(nums.begin(), nums.end()); // Sort the input vector to handle duplicates
        generate(0, nums, v); // Start generating subsets from index 0
        return ans; // Return the resulting subsets
    }
};
