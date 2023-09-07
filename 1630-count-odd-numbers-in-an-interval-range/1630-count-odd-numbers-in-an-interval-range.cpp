class Solution {
public:
    // Recursive function to count odd numbers within a given range
    int count(int low, int high, int c = 0) {
        // Base case: If the lower bound exceeds the upper bound, return the count
        if (low > high) {
            return c;
        }

        // Check if the current number (low) is odd
        if (low % 2 == 1) {
            // Increment the count if it's odd
            c++;
        }

        // Recursively call the function with the next number and the same count
        return count(low + 1, high, c);
    }

    // Public function to count odd numbers within a range
    int countOdds(int low, int high) {
        // Call the recursive count function with the specified range
        return count(low, high);
    }
};
