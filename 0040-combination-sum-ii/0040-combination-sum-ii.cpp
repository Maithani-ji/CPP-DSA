class Solution {//recuesive backtracking
public:
    vector<vector<int>> ans; // This vector will store the resulting combinations

    // Recursive function to generate combinations
    void generate(vector<int>& current, vector<int>& cand, int index, int sum, int target) {
        if (sum == target) {
            ans.push_back(current); // If the sum matches the target, add the combination to the result
            return;
        }

        if (index == cand.size() || sum > target) {
            return; // If we've reached the end of the candidates or the sum is too large, backtrack
        }

        // Include the current element in the combination
        current.push_back(cand[index]);
        generate(current, cand, index + 1, sum + cand[index], target);

     
        // Skip duplicates (candidates with the same value)
        while (index + 1 < cand.size() && cand[index] == cand[index + 1]) {
            index++;
        }

           // Backtrack: Remove the last added element
        current.pop_back();

        // Generate combinations without the current element
        generate(current, cand, index + 1, sum, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<int> current; // Vector to hold the current combination
        sort(cand.begin(), cand.end()); // Sort the candidates to handle duplicates
        generate(current, cand, 0, 0, target); // Start generating combinations
        return ans; // Return the resulting combinations
    }
};

/*using int2 = pair<int, int>;// DP
class Solution {
public:
int n;
vector<vector<int>> dfs(int i, int target, vector<int2>& nWm, vector<vector<vector<vector<int>>>>& dp) 
{
        if (target == 0) {
            return {{}};
        }

        if (i == n || target < 0) {
            return {};
        }

        if (!dp[i][target].empty()) {
            return dp[i][target];
        }

        auto [x, m] = nWm[i];
        vector<vector<int>> result;
        for (int j = 0; j <= m; j++) {
            vector<vector<int>> combinations = dfs(i + 1, target - j * x, nWm, dp);
            for (int k = 0; k < combinations.size(); k++) {
                for (int l = 1; l <= j; l++) {
                    combinations[k].push_back(x);
                }
                result.push_back(combinations[k]);
            }
        }       
        return  dp[i][target] = result;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int2> nWm;
        nWm.push_back({candidates[0], 1});
        int idx = 0;
        for (int i = 1; i < candidates.size(); i++) {
            if (candidates[i] == candidates[i - 1]) {
                nWm[idx].second++;
            } else {
                nWm.push_back({candidates[i], 1});
                idx++;
            }
        }
        n=nWm.size();

        vector<vector<vector<vector<int>>>> 
        dp(n, vector<vector<vector<int>>>(target + 1));

        return dfs(0, target, nWm, dp);
    } 
};*/
