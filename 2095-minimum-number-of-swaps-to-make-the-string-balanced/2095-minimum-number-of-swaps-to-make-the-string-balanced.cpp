// class Solution {
// public:
//     int minSwaps(string s) {
//         stack<char> st;    // Stack to keep track of unmatched brackets.
//         int count = 0;     // Count of unbalanced brackets.

//         // Iterate through each character in the input string.
//         for (auto c : s) {
//             if (c == '[') {
//                 st.push(c);  // If an opening bracket is encountered, push onto the stack.
//             } else {
//                 // If a closing bracket is encountered and there's a matching opening bracket in the stack, pop it.
//                 if (!st.empty() && c == ']') {
//                     st.pop();
//                 } else {
//                     count++;   // If no matching opening bracket, count as an unbalanced bracket.
//                 }
//             }
//         }
        
//         // The number of swaps needed is half the count of unbalanced brackets, rounded up.
//         return (count + 1) / 2;
//     }
// };
         //                        SAME as ABOVE 
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int count = 0;

        // Iterate through each character in the string.
        for (auto c : s) {
            if (!st.empty() && st.top() == '[' && c == ']') {
                st.pop(); // If a closing bracket matches an opening bracket, pop from the stack.
            } else {
                st.push(c); // Otherwise, push the character onto the stack.
            }
        }

        // Iterate through the remaining characters in the stack to count the unbalanced brackets.
        while (!st.empty()) {
            if (st.top() == '[') {
                count++; // Count unbalanced opening brackets.
                st.pop();
            } else {
                st.pop(); // Pop other characters from the stack.
            }
        }

        // The number of swaps needed is half the count of unbalanced brackets, rounded up.
        return (count + 1) / 2;
    }
};
