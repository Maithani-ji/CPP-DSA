class Solution {
public:
    // Custom sorting function to compare two integers after converting them to strings.
    static bool customsort(int a, int b) {
        string str1 = to_string(a);
        string str2 = to_string(b);
        // Compare by concatenating strings to ensure the largest number comes first.
        return str1 + str2 > str2 + str1;
    }

    string largestNumber(vector<int>& nums) {
       // vector<int> ans;  // A vector to store the integers from 'nums'.

       // for (auto n : nums) {
       //     ans.push_back(n);  // Copy each number from 'nums' to 'ans'.
       // }

        // Sort 'ans' in non-increasing order based on custom sorting criteria.
        sort(nums.begin(), nums.end(), customsort);

        string str;  // Initialize an empty string to store the result.

        for (auto i : nums) {
            // Convert each number 'i' to a string and append it to the 'str'.
            str = str + to_string(i);
        }
        
        // Remove leading zeros
         while (str[0] == '0' && str.length() > 1) {
            str.erase(0, 1);
        }
        return str;  // Return the string 'str' representing the largest number.
    }
};
