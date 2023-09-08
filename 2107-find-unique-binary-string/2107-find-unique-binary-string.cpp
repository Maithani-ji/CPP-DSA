class Solution {
public:
    vector<string> ans; // A vector to store the generated binary strings

    // Recursive function to generate binary strings
    void generate(vector<string> nums, int n, int i = 0, string s = "") {
        if (i == n) {
            // If the generated binary string 's' is not in the 'nums' vector, add it to 'ans'
            if (find(nums.begin(), nums.end(), s) == nums.end()) {
                ans.push_back(s);
                return;
            }
            return;
           
        }
        if(!ans.empty())
        {
            return;
        }
        // Recursively generate binary strings by appending '0' and '1' at the current position
        generate(nums, n, i + 1, s + "0");
        generate(nums, n, i + 1, s + "1");
    }

    // Function to find a binary string that's not in the 'nums' vector
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size(); // Determine the length of the binary strings

        // Generate binary strings of length 'n'
        generate(nums, n);

        // The first binary string in 'ans' that's not in 'nums' is the answer
        return ans[0];
    }
};
