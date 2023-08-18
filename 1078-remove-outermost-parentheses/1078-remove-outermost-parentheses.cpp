class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st; // Initialize an empty stack to keep track of parentheses
        string ans; // Initialize an empty string to store the result

        for (auto c : s) {
            if (c == '(') { // If an opening parenthesis is encountered
                if (!st.empty()) { // If the stack is not empty, it's not the outermost '('
                    ans += c; // Append the '(' to the result
                }
                st.push(c); // Push the '(' onto the stack
            }

            if (c == ')') { // If a closing parenthesis is encountered
                st.pop(); // Pop the corresponding opening parenthesis from the stack
                if (!st.empty()) { // If the stack is not empty, it's not the outermost ')'
                    ans += c; // Append the ')' to the result
                }
            }
        }

        return ans; // Return the final result string with outermost parentheses removed
    }
};
//This code iterates through the string while maintaining a count of open and close parentheses. It adds the characters to the result string only if they are not part of the outermost parentheses. However, this approach has a time complexity of O(n^2) due to string concatenations, where n is the length of the input string.
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string result = "";
//         int count = 0;
        
//         for (char c : s) {
//             if (c == '(') {
//                 if (count > 0) {
//                     result += c;
//                 }
//                 count++;
//             }
//             if (c == ')') {
//                 count--;
//                 if (count > 0) {
//                     result += c;
//                 }
//             }
//         }
        
//         return result;
//     }
// };
