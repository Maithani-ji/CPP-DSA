class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // Initialize a vector to store the sequence of operations.
        vector<string> ans;

        // Initialize a variable to keep track of the current number to consider.
        int start = 1;

        // Iterate through each element in the target vector.
        for (auto i : target) {
            // Perform "Push" and "Pop" operations until the current value (start) matches the target value (i).
            while (i != start) {
                // Add a "Push" operation to the sequence.
                ans.push_back("Push");

                // Add a "Pop" operation to the sequence.
                ans.push_back("Pop");

                // Increment the current number being considered.
                start++;
            }

            // Once the current value matches the target value, add a "Push" operation to the sequence.
            ans.push_back("Push");

            // Increment the current number being considered.
            start++;
        }

        // Return the sequence of operations.
        return ans;
    }
};

// class Solution {//using stack 
// public:
//     vector<string> buildArray(vector<int>& target, int n) {
//         vector<string> ans;
//         stack<int> stk;
//         int current = 1;

//         for (int num : target) {
//             while (current < num) {
//                 stk.push(current);
//                 ans.push_back("Push");
//                 ans.push_back("Pop");
//                 current++;
//             }

//             stk.push(num);
//             ans.push_back("Push");
//             current++;
//         }

//         return ans;
//     }
// };

