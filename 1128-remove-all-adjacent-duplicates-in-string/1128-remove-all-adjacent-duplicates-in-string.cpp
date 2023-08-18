// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char> st; // Stack to store characters
//         string ans; // Resultant string
        
//         for (int i = s.size() - 1; i >= 0; i--) { // Iterate through the string in reverse
//             if (!st.empty() && s[i] == st.top()) { // If the current character matches the top of the stack
//                 st.pop(); // Pop the character from the stack
//             } else {
//                 st.push(s[i]); // Push the character onto the stack
//             }
//         }
        
//         while (!st.empty()) { // Construct the resultant string from the stack
//             ans += st.top();
//             st.pop();
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    string removeDuplicates(string s) {
        int j = 0; // Use 'j' as the index for building the answer
        
        for (int i = 0; i < s.size(); i++) {
            // If 'j' is greater than 0 and the current character matches the last character in the answer
            if (j > 0 && s[i] == s[j - 1]) {
                j--; // Decrement 'j' to remove the duplicate
            } else {
                s[j] = s[i]; // Otherwise, copy the character to the answer
                j++; // Increment 'j'
            }
        }
        
        return s.substr(0, j); // Return the non-duplicate part of the string
    }
};
