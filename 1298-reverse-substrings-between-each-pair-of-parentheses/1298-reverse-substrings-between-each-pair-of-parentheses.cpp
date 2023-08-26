class Solution {
public:
    string reverseParentheses(string s) {

        string ans; // Initialize an empty string to store the result
        stack<int> st; // Initialize a stack to keep track of opening parenthesis positions

        // Loop through each character in the input string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the position of an opening parenthesis onto the stack
            } else if (s[i] == ')') {
                // When encountering a closing parenthesis, reverse the substring enclosed by the corresponding opening parenthesis
                reverse(s.begin() + st.top(), s.begin() + i);
                st.pop(); // Pop the corresponding opening parenthesis position from the stack
            }
        }

        // Loop through each character in the modified string
        for (auto i : s) {
            if (isalpha(i)) {
                ans += i; // Append alphabetic characters to the answer string
            }
        }
        return ans; // Return the final reversed and processed string without parentheses
    }
};
