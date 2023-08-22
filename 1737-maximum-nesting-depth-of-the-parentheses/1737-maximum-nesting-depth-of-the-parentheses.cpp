class Solution {//using without any extra space 
public:
    int maxDepth(string s) {
        int currentDepth = 0; // Initialize the current depth to 0
        int maxDepth = 0; // Initialize the maximum depth to 0

        for (char c : s) {
            if (c == '(') { // If an opening parenthesis is encountered
                currentDepth++; // Increment the current depth
                maxDepth = max(maxDepth, currentDepth); // Update max depth if necessary
            } else if (c == ')') { // If a closing parenthesis is encountered
                currentDepth--; // Decrement the current depth (closing a nested level)
            }
        }

        return maxDepth; // Return the maximum depth of nested parentheses
    }
};

 //Using Stack 
 // class Solution {
// public:
//     int maxDepth(string s) {

//         stack<char> st; // Create a stack to keep track of opening parentheses
//         int ans = 0; // Initialize the answer to a very small value

//         for (auto c : s) {
//             if (c == '(') { // If an opening parenthesis is encountered
//                 st.push(c); // Push onto the stack
//                 ans = max(ans,(int)(st.size())); // Update max depth
//             } else if (c == ')') { // If a closing parenthesis is encountered
//                 st.pop(); // Pop from the stack (closing a nested level)
//             }
//         }

//         return ans; // Return the maximum depth of nested parentheses
//     }
// };
