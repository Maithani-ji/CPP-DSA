class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0; // Initialize the operations count to zero

        for (auto c : logs) {
            if (c == "../" && ans > 0) {
                // If encountering "../" and there are operations to undo, decrement count
                ans--;
            } else if (c != "../" && c != "./") {
                // If not encountering "../" or "./", increment count for valid operations
                ans++;
            }
        }

        return ans; // Return the total count of operations
    }
};


//Using Stack 
//class Solution {
// public:
//     int minOperations(vector<string>& s) {
//         stack<string> st; // Create a stack to simulate directory navigation

//         for (auto c : s) {
//             if (c == "../" )
//             {if(!st.empty()) {
//                 // If encountering "../" and stack is not empty, simulate moving up one level
//                 st.pop(); // Pop the top directory name from the stack
//             }} else {
//                 if (c == "./") {
//                     continue; // Skip the current directory notation, as it doesn't affect navigation
//                 } else {
//                     st.push(c); // Push valid directory name onto the stack
//                 }
//             }
//         }

//         return st.size(); // Return the number of remaining directory names in the stack
//     }
// };
