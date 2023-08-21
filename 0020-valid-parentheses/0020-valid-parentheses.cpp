class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Create a stack to keep track of opening parentheses

        for (auto c : s) {  // Iterate through each character in the string
            if (!st.empty() &&
                ((st.top() == '(' && c == ')') ||
                 (st.top() == '[' && c == ']') ||
                 (st.top() == '{' && c == '}'))) {
                // If the stack is not empty and the current character matches the top of the stack
                st.pop();  // Pop the top element as its corresponding closing parenthesis is found
            } else {
                st.push(c);  // Otherwise, push the current character onto the stack
            }
        }

        return st.empty();  // If the stack is empty, all parentheses are matched; otherwise, return false
    }
};
/*class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || !isMatching(st.top(), c)) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }

private:
    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
};
*/