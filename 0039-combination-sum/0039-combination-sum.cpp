
class Solution {//using generate all subset ALGO WITH MODIFICATION like-> sum , target, and making subset of repetitive element , and moving forward when found val sum greater  

                //BRUTE FORCE // not DYNAMIC PROGRAMMING used

public:
    vector<vector<int>> ans;  // Initialize a vector to store the combinations that sum up to the target.

    // Recursive function to generate combinations.
    void generate(vector<int> a, vector<int> cand, int n, int i, int sum, int t) {
        if (i == cand.size()) {
            return;  // Base case: If we've processed all elements in the candidates, return.
        }
        if (sum >= t) {
            if (sum == t) {
                ans.push_back(a);  // If the current sum matches the target, add the combination to 'ans'.
            }
            return;  // Return regardless of whether sum matches the target or not.
        }

        a.push_back(cand[i]);  // Include the current candidate element in the combination.
        sum += cand[i];        // Update the current sum.

        // Recursive call to include the current candidate element again (since it can be used multiple times).
        generate(a, cand, n, i, sum, t);// not using i+1, since i'th pos element can be used multiple times.

        a.pop_back();  // Remove the last element from the combination.
        sum -= cand[i];  // Update the sum after removing the last element.

        // Recursive call to move to the next candidate element (i+1) and continue generating combinations.
        generate(a, cand, n, i + 1, sum, t);//i+1 used since , if prev pos element sum got >target, then remove it and move forward
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> a;  // Initialize an empty combination.
        generate(a, cand, cand.size(), 0, 0, target);  // Start generating combinations.

        return ans;  // Return the list of combinations that sum up to the target.
    }
};

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<vector<int>>> dp(target + 1); // Initialize a 3D vector to store combinations for each target sum.
//         dp[0].push_back({}); // Base case: There's one way to achieve a sum of 0, which is an empty combination.
        
//         for (int num : candidates) {
//             for (int i = num; i <= target; ++i) {
//                 for (vector<int> comb : dp[i - num]) {
//                     comb.push_back(num);
//                     dp[i].push_back(comb);
//                 }
//             }
//         }
        
//         return dp[target]; // Return combinations that sum up to the target.
//     }
// };
