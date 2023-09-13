class Solution {// using permutation algo with sets as extra space 
public:
    set<vector<int>> v; // Set to store unique permutations

    // Recursive function to generate unique permutations
    void generate(vector<int>& nums, int index) {
        if (index == nums.size()) { // If the current index reaches the size of the input vector
            v.insert(nums); // Add the current unique permutation to the result set
            return; // Return to backtrack and explore other permutations
        }

        for (int i = index; i < nums.size(); i++) { // Iterate through elements starting from the current index
            swap(nums[i], nums[index]); // Swap the current element with the element at the current index
            generate(nums, index + 1); // Recursively generate unique permutations for the remaining elements
            swap(nums[i], nums[index]); // Swap the elements back for backtracking
        }
    }

    // Function to generate all unique permutations of an input vector
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        generate(nums, 0); // Start generating unique permutations from index 0

        vector<vector<int>> ans(v.begin(), v.end()); // Convert the set to a vector
        return ans; // Return the result vector containing all unique permutations
    }
};

// class Solution {// using permutation algo without using extra space as sets 
// public:
//     vector<vector<int>> ans; // Vector to store permutations

//     // Recursive function to generate permutations
//     void generate(vector<int>& nums, int index) {
//         if (index == nums.size()) { // If the current index reaches the size of the input vector
//             ans.push_back(nums); // Add the current permutation to the result vector
//             return; // Return to backtrack and explore other permutations
//         }

//         for (int i = index; i < nums.size(); i++) { // Iterate through elements starting from the current index
//             swap(nums[i], nums[index]); // Swap the current element with the element at the current index

//             // Handle duplicate elements by skipping them
//             while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
//                 i++;
//             }

//             generate(nums, index + 1); // Recursively generate permutations for the remaining elements
//             swap(nums[i], nums[index]); // Swap the elements back for backtracking
//         }
//     }

//     // Function to generate all permutations of an input vector with handling duplicates
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         generate(nums, 0); // Start generating permutations from index 0
//         return ans; // Return the result vector containing all permutations
//     }
// };
