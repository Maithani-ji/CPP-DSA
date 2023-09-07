class Solution {
public:

    // Helper function to reverse the digits of an integer with overflow check
    int rev(int x, int ans = 0) {
        if (x == 0) {
            return ans;
        }

        // Check for integer overflow
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
            return 0; // Overflow condition, return 0
        }

        int temp = x % 10;
        ans = ans * 10 + temp; // Add the current digit to the reversed number
        return rev(x / 10, ans); // Recursively reverse the remaining digits
    }

    // Main function to reverse an integer while handling the sign
    int reverse(int x) {
        bool n = false; // Flag to check if the input number is negative
        if (x < 0) {
            n = true; // Set the flag to true if the number is negative
        }

        // Reverse the absolute value of x using the helper function
        int reversed = rev(abs(x));

        // Apply the sign back to the reversed number if needed
        if (n) {
            reversed *= -1;
        }

        return reversed;
    }
};
