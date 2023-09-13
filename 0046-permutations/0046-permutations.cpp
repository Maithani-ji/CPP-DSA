class Solution {//optimal without using exta space as map and storing nums factorial permutation
public:
    vector<vector<int>> ans; // Vector to store permutations

    // Recursive function to generate permutations
    void generate(vector<int>& nums, int index) {
        if (index == nums.size()) { // If the current index reaches the size of the input vector
            ans.push_back(nums); // Add the current permutation to the result vector
            return; // Return to backtrack and explore other permutations
        }

        for (int i = index; i < nums.size(); i++) { // Iterate through elements starting from the current index
            swap(nums[i], nums[index]); // Swap the current element with the element at the current index
            generate(nums, index + 1); // Recursively generate permutations for the remaining elements
            swap(nums[i], nums[index]); // Swap the elements back for backtracking
        }
    }

    // Function to generate all permutations of an input vector
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums, 0); // Start generating permutations from index 0
        return ans; // Return the result vector containing all permutations
    }
};

// class Solution {// using extra space as map n+m  m is space used by v 
// public:
//     vector<vector<int>> ans; // Vector to store permutations
//     vector<int> v; // Vector to store the current permutation being generated

//     // Recursive function to generate permutations
//     void generate(vector<int>& nums, vector<int>& check) {
//         if (v.size() == nums.size()) { // If the current permutation is of the same size as the input
//             ans.push_back(v); // Add the current permutation to the result vector
//             return; // Return to backtrack and explore other permutations
//         }

//         for (int i = 0; i < nums.size(); i++) { // Iterate through the elements of the input vector
//             if (!check[i]) { // If the element hasn't been used in the current permutation
//                 v.push_back(nums[i]); // Add the element to the current permutation
//                 check[i] = 1; // Mark the element as used
//                 generate(nums, check); // Recursively generate permutations
//                 check[i] = 0; // Unmark the element for backtracking
//                 v.pop_back(); // Remove the element from the current permutation
//             }
//         }
//     }

//     // Function to generate all permutations of an input vector
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> check(nums.size(), 0); // Vector to keep track of used elements
//         generate(nums, check); // Generate permutations using recursion
//         return ans; // Return the result vector containing all permutations
//     }
// };
