class Solution {
public:
 bool checkValidString(string s) {
    int minOpen = 0;   // Keep track of minimum unmatched '(' count
    int maxOpen = 0;   // Keep track of maximum unmatched '(' count

    for (char c : s) {
        if (c == '(') {
            minOpen++;    // Treat '*' as '(' for minimum unmatched count
            maxOpen++;    // Treat '*' as ')' for maximum unmatched count
        } else if (c == ')') {
            minOpen = max(0, minOpen - 1);  // Treat '*' as '(' for minimum unmatched count
            maxOpen--;    // Treat '*' as ')' for maximum unmatched count
        } else {  // '*'
            minOpen = max(0, minOpen - 1);  // Treat '*' as '(' for minimum unmatched count
            maxOpen++;    // Treat '*' as ')' for maximum unmatched count
        }

        if (maxOpen < 0) {
            return false;  // More ')' than '(' and '*' at this point, invalid
        }
    }

    return minOpen == 0;  // If all '(' are matched, the string is valid
}
};


// class Solution { // Using STACK T-n S-n
// public:
//     bool checkValidString(string s) {
//         stack<char> st, ast;  // Create two stacks: st for '(' indices, ast for '*' indices

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 st.push(i);  // Push index of '(' onto the stack
//             } else if (s[i] == '*') {
//                 ast.push(i);  // Push index of '*' onto the stack
//             } else {  // This handles the case of encountering ')'
//                 if (!st.empty()) {
//                     st.pop();  // If there's a matching '(', pop it from the stack
//                 } else if (!ast.empty()) {
//                     ast.pop();  // If there's no matching '(', pop a '*' from the stack
//                 } else {
//                     return false;  // Unmatched ')' without '(' or '*' to balance
//                 }
//             }
//         }
        
//         while (!st.empty()) {
//             if (!ast.empty() && st.top() < ast.top()) {
//                 st.pop();  // Match '*' with '('
//                 ast.pop();
//             } else {
//                 return false;  // Unmatched '(' without '*' to balance
//             }
//         }
        
//         return true;  // All parentheses and '*' matched and balanced
//     }
// };
