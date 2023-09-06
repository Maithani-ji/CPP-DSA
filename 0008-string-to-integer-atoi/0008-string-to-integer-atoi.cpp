class Solution {
    long atoi(string s, int sign, int i, long result) {
        // Check for integer overflow
        if (sign == 1 && sign * result >= INT_MAX) {
            return INT_MAX;
        }
        // Check for integer underflow
        if (sign == -1 && sign * result <= INT_MIN) {
            return INT_MIN;
        }
        // Base case: If we reach the end of the string or encounter a non-digit character, return the result.
        if (i >= s.size() || !isdigit(s[i])) {
            return sign * result;
        }

        // Recursively process the next character in the string and update the result.
        result = atoi(s, sign, i + 1, (result * 10 + (s[i] - '0')));

        return result;
    }

public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;

        // Remove leading whitespaces
        while (i < n && s[i] == ' ')
            ++i;

        // Handle sign characters
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // Call the recursive atoi function to convert the string to an integer
        return atoi(s, sign, i, 0);
    }
};


// //iterative 
// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0;              // Initialize the index for iterating through the string.
//         int n = s.size();       // Get the length of the input string.
//         int sign = 1;           // Initialize the sign of the result as positive.
//         long result = 0;        // Use long to handle potential integer overflow.

//         // Remove leading whitespaces
//         while (i < n && s[i] == ' ')
//             ++i;

//         // Check for a sign character
//         if (i < n && (s[i] == '+' || s[i] == '-')) {
//             sign = (s[i] == '-') ? -1 : 1;  // Set the sign based on the presence of '-'.
//             ++i;                            // Move to the next character after the sign.
//         }

//         // Process digits
//         while (i < n && isdigit(s[i])) {
//             result = result * 10 + (s[i] - '0');  // Accumulate digits in the result.

//             // Check for integer overflow and underflow
//             if (result * sign > INT_MAX)
//                 return INT_MAX;
//             if (result * sign < INT_MIN)
//                 return INT_MIN;

//             ++i;  // Move to the next character in the string.
//         }

//         return result * sign;  // Return the final result with the appropriate sign.
//     }
// };
