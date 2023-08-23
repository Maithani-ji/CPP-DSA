class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st, ast;  // Create two stacks: st for '(' indices, ast for '*' indices

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  // Push index of '(' onto the stack
            } else if (s[i] == '*') {
                ast.push(i);  // Push index of '*' onto the stack
            } else {  // This handles the case of encountering ')'
                if (!st.empty()) {
                    st.pop();  // If there's a matching '(', pop it from the stack
                } else if (!ast.empty()) {
                    ast.pop();  // If there's no matching '(', pop a '*' from the stack
                } else {
                    return false;  // Unmatched ')' without '(' or '*' to balance
                }
            }
        }
        
        while (!st.empty()) {
            if (!ast.empty() && st.top() < ast.top()) {
                st.pop();  // Match '*' with '('
                ast.pop();
            } else {
                return false;  // Unmatched '(' without '*' to balance
            }
        }
        
        return true;  // All parentheses and '*' matched and balanced
    }
};
