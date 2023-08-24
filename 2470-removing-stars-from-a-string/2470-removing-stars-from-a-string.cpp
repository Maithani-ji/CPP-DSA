class Solution {
public:
    string removeStars(string s) {
        // Create a stack to hold characters while filtering out consecutive asterisks.
        stack<char> st;

        // Iterate through each character in the input string.
        for(auto c : s) {
            // If the stack is not empty and the current character is an asterisk,
            // pop the top character to filter out consecutive asterisks.
            if(!st.empty() && c == '*') {
                st.pop();
            }
            // If the current character is not an asterisk, push it onto the stack.
            else {
                st.push(c);
            }
        }

        // Create a string to hold the final modified result.
        string ans="";

        // Reconstruct the final string while emptying the stack.
        while(!st.empty()) {
            // Concatenate the top character of the stack to the back of the result.
            ans += st.top();
            // Pop the character from the stack.
            st.pop();
        }
        
         reverse(ans.begin(),ans.end());
        // Return the modified string with consecutive asterisks removed.
        return ans;
    }
};
