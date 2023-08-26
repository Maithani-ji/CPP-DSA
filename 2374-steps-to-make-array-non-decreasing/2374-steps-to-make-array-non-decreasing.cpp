class Solution {
public:
    int totalSteps(vector<int>& nums) {

        stack<pair<int, int>> st;  // Initialize a stack to store pairs (element, steps)
        
        int ans = -1;  // Initialize the maximum step count as -1 (for comparison)
        for (int i = nums.size() - 1; i >= 0; i--) {
            int count = 0;  // Initialize the step count for the current element
            while (!st.empty() and st.top().first < nums[i]) {
                // While there are elements in the stack and the top element is larger
                // than the current element, indicating a need for adjustment
                count = max(count + 1, st.top().second); // Update the step count
                st.pop();  // Remove the element from the stack
            }
            ans = max(ans, count);  // Update the maximum step count seen so far
            st.push({nums[i], count});  // Push the current element and its step count onto the stack
        }
        
        return ans;  // Return the maximum step count required to make the sequence non-decreasing
    }
};
