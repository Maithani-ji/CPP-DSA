class Solution {// optimal 
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res; // Initialize an empty result string to store the unique binary string.


//*********** since given --> LENGTH of string in array IS SAME as LENGTH of ARRAY 
     
        for (int i = 0; i < nums.size(); i++) {

// check each ith element at ith char & store inverted value of that posn in res --> thus gettinG --> UNIQUE STRING  // THIS WORKS only BECAUSE given--> lnegth of element and array is same 

            res += nums[i][i] == '1' ? '0' : '1';

        }


        // The 'res' string now contains the unique binary string created by flipping bits at each position.
        return res; // Return the unique binary string.
    }
};

/*class Solution {//using generate all binary string ALGORITHM to solve to unique binary string prob
public:
    vector<string> ans; // A vector to store the generated binary strings

    // Recursive function to generate binary strings
    void generate(vector<string> nums, int n, int i = 0, string s = "") {
        if (i == n) {
            // If the generated binary string 's' is not in the 'nums' vector, add it to 'ans' 

            if (find(nums.begin(), nums.end(), s) == nums.end()) {// (diff)
                ans.push_back(s); // (diff)
            }
            return;
           
        }
        if(!ans.empty())// (diff)   for checking unique // if true just stop moving forward we found the missing 
        {
            return;//diff
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
*/