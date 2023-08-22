
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;  // Create a stack to hold characters

        // Iterate through each character in the input string s
        for (auto c : s) {
            // Check if the stack is not empty and the current character c is the opposite case of the top element
            if (!st.empty() && abs(st.top() - c) == 32) {  
                st.pop();  // If a pair is found, pop the top element from the stack
            } else {
                st.push(c);  // If not a pair, push the current character onto the stack
            }
        }

        string ans;  // Create a string to hold the final result

        // Construct the final string by popping elements from the stack and adding them to the beginning of the result
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;  // Return the resulting string
    }
};
