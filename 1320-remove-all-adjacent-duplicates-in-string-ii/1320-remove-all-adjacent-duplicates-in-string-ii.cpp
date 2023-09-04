class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // Create a stack to store characters and their counts.

        // Iterate through each character in the input string.
        for (auto c : s) {
            if (st.empty() || st.top().first != c) {
                // If the stack is empty or the current character is different from the top of the stack,
                // push a new pair (character, count) onto the stack.
                st.push({ c, 1 });
            } else {
                // If the current character is the same as the top of the stack, update the count.
                auto prev = st.top();
                st.pop();
                st.push({ prev.first, prev.second + 1 });
            }

            if (st.top().second == k) {
                // If the count of the current character reaches 'k', pop it from the stack.
                st.pop();
            }
        }

        string ans;

        // Reconstruct the result string from the characters left in the stack.
        while (!st.empty()) {
            while (st.top().second--) {
                ans += st.top().first;
            }
            st.pop();
        }

        reverse(ans.begin(), ans.end()); // Reverse the result string as it was constructed in reverse order.
        return ans;
    }
};
