// class Solution {
// public:
//     string decodeAtIndex(string s, int k) {
//         int64_t size = 0; // Initialize the size variable to keep track of the total decoded length.

//         // Iterate through the characters in the input string.
//         for(auto c : s) {
//             if(isdigit(c)) {
//                 size *= c - '0'; // If the character is a digit, update the size by multiplying it.
//             } else {
//                 size++; // If the character is not a digit, increment the size.
//             }
//         }

//         // Traverse the string in reverse order to find the decoded character at index 'k'.
//         for(int i = s.size() - 1; i >= 0; i--) {
//             k = k % size; // Reduce 'k' to account for repetitions.

//             // If 'k' becomes zero and the current character is not a digit, return it as the answer.
//             if (k == 0 && !isdigit(s[i])) {
//                 // string ans;
//                 // ans+=s[i];
//                 // return ans;
//                 return string(1, s[i]); // Return the current character as a string.
//             }

//             // If the current character is a digit, adjust the 'size' variable accordingly.
//             if (isdigit(s[i])) {
//                 int digit = s[i] - '0';
//                 size /= digit;
//             } else {
//                 size--; // Decrement the size if the character is not a digit.
//             }
//         }

//         return ""; // Return an empty string if no condition is satisfied.
//     }
// };

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<pair<long long, char>> stk; // Using a stack to keep track of characters and their accumulated sizes.
        long long size = 0; // Initialize the total size.

        for (char c : s) {
            if (isdigit(c)) {
                size *= c - '0';
            } else {
                size++;
            }
            
            stk.push({size, c}); // Push the character and its corresponding accumulated size onto the stack.
        }

        while (!stk.empty()) {
            auto [charSize, c] = stk.top();
            stk.pop();
            
            k %= charSize; // Adjust 'k' based on the accumulated size of the current character.
            
            if (k == 0 && !isdigit(c)) {
                return string(1, c);
            }
            
            if (isdigit(c)) {
                size = charSize / (c - '0');
            } else {
                size--;
            }
        }

        return "";
    }
};
