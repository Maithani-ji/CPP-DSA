
class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Initialize a stack to keep track of characters.

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'c') { // If the current character is 'c'.
                if (st.size() >= 2 && st.top() == 'b') { // Check if there are at least two characters in the stack and the top character is 'b'.
                    st.pop(); // Pop 'b'.
                    if (st.top() == 'a') { // Check if the character before 'b' is 'a'.
                        st.pop(); // Pop 'a'.
                    } else {
                        return false; // Invalid sequence if 'a' is not before 'b'.
                    }
                } else {
                    return false; // Invalid sequence if 'b' is not on top of the stack or there are fewer than two characters in the stack.
                }
            } else {
                st.push(s[i]); // Push characters other than 'c' onto the stack.
            }
        }

        return st.empty(); // If the stack is empty at the end, the string is valid; otherwise, it's not valid.
    }
};
