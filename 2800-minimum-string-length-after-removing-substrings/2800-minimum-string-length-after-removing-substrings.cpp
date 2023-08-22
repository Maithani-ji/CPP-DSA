class Solution {
public:
    int minLength(string s) {
        stack<char> st; // Create a stack to keep track of characters

        for (auto c : s) {
            if (!st.empty() && ((c == 'B' && st.top() == 'A') || (c == 'D' && st.top() == 'C'))) {
                // If the stack is not empty and the current character forms a valid pair
                // ('A' and 'B') or ('C' and 'D') with the top character, pop the top character.
                st.pop();
            } else {
                st.push(c); // Push the current character onto the stack.
            }
        }

        return st.size(); // Return the remaining characters count in the stack.
    }
};
//                     Using SWITCH with STACK
// class Solution {
// public:
//     int minLength(string s) {
//         stack<char> st; // Create a stack to keep track of characters

//         for (auto c : s) {
//             if (!st.empty()) {
//                 switch (c) {
//                     case 'B':
//                         if (st.top() == 'A')
//                             st.pop();
//                         else
//                             st.push(c);
//                         break;
//                     case 'D':
//                         if (st.top() == 'C')
//                             st.pop();
//                         else
//                             st.push(c);
//                         break;
//                     default:
//                         st.push(c);
//                         break;
//                 }
//             } else {
//                 st.push(c);
//             }
//         }

//         return st.size(); // Return the remaining characters count in the stack.
//     }
// };
