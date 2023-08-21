// class Solution {//going through all the possibilities
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n = nums.size();
//         int maxWidth = 0;

//         // Loop through all pairs of indices (i, j) where i < j
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] <= nums[j]) {
//                     maxWidth = max(maxWidth, j - i);
//                 }
//             }
//         }

//         return maxWidth;
//     }
// };

class Solution {//using stack 
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array
        if (n < 2) {
            return 0;  // If there are less than 2 elements, no ramp is possible
        }

        stack<int> st;  // Create a stack to hold potential candidate indices

        // Find candidates for j positions (indices of potential ramps)
        for (int i = 0; i < n; i++) {// storing minumum val indices from start 
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);  // Push the current index onto the stack if it's a candidate for j
            }
        }

        int ans = 0;  // Initialize the answer to store the maximum width ramp

        // Find the maximum width ramp by comparing candidates to i positions
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());  // Update the answer if a wider ramp is found
                st.pop();  // Pop candidates from the stack as they are no longer needed
            }
        }

        return ans;  // Return the maximum width ramp found
    }
};
