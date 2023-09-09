class Solution {// just add the element & move forward or not add the element & move forward-->pop_back
public:
    vector<vector<int>> ans; // This vector will store all the subsets.

    // Recursive function to generate subsets.
    void generate(vector<int> a, int i, int n, vector<int> nums) {
        // Base case: If we have processed all elements in 'nums', add the current subset to 'ans' and return.
        if (i == n) {
            ans.push_back(a);
            return;
        }
        
        // Include the current element from 'nums' in the current subset.
        a.push_back(nums[i]);
        generate(a, i + 1, n, nums); // Recursively generate subsets with the current element.
        
        // Exclude the current element from the current subset.
        a.pop_back();
        generate(a, i + 1, n, nums); // Recursively generate subsets without the current element.
    }

    // Main function to generate subsets from the input vector 'nums'.
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a; // Initialize an empty vector to represent the current subset.
        
        // Start generating subsets with the 'generate' function.
        generate(a, 0, nums.size(), nums);

        // Return the final 'ans' containing all subsets.
        return ans;
    }
};
