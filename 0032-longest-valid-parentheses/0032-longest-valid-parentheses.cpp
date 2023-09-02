// class Solution {// using stack T-n S-n
// public:
//     int longestValidParentheses(string s) {
//         stack<int> st;  // Initialize a stack to store indices of opening parentheses.
//         st.push(-1);    // Push -1 onto the stack as a starting point.
//         int mx = 0;     // Initialize a variable to keep track of the maximum valid length.

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 st.push(i);  // Push the index of an opening parenthesis onto the stack.
//             } else {
//                 st.pop();  // Pop the top of the stack since a closing parenthesis is encountered.
//                 if (st.empty()) {
//                     st.push(i);  // If the stack is empty, push the current index.
//                 } else {
//                     mx = max(mx, i - st.top());  // Calculate the valid length and update mx.
//                 }
//             }
//         }
//         return mx;  // Return the maximum valid length found in the string.
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0;  // Initialize a counter for open parentheses '('.
        int r = 0;  // Initialize a counter for close parentheses ')'.
        int mx = 0; // Initialize a variable to store the maximum valid length.

        // Traverse the string from left to right.
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                l++; // Increment the count of open parentheses.
            } else {
                r++; // Increment the count of close parentheses.
            }
            if (l == r) {
                // If the counts of open and close parentheses are equal, a valid substring is found.
                // Update mx with the maximum valid length found so far.
                mx = max(mx, l * 2);
            } else if (r > l) {
                // If there are more close parentheses than open ones, reset the counters.
                l = 0;
                r = 0;
            }
        }

        // Reset counters for the second pass.
        l = 0;
        r = 0;

        // Traverse the string from right to left.
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                l++; // Increment the count of open parentheses.
            } else {
                r++; // Increment the count of close parentheses.
            }
            if (l == r) {
                // If the counts of open and close parentheses are equal, a valid substring is found.
                // Update mx with the maximum valid length found so far.
                mx = max(mx, l * 2);
            } else if (l > r) {
                // If there are more open parentheses than close ones, reset the counters.
                l = 0;
                r = 0;
            }
        }

        // Return the maximum valid length found in the input string.
        return mx;
    }
};
