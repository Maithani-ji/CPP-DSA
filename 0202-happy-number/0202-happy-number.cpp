class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;  // To keep track of seen numbers and detect cycles.

        while (n != 1) {
            if (seen.count(n)) {
                return false;  // If a number repeats, it's not a happy number.
            }
            seen.insert(n);  // Add the current number to the set.

            int sum = 0;
            while (n > 0) {
                int digit = n % 10;  // Extract the last digit.
                sum += digit * digit;  // Square and add the digit.
                n /= 10;  // Remove the last digit.
            }
            n = sum;  // Set n to the sum for the next iteration.
        }

        return true;  // If n eventually becomes 1, it's a happy number.
    }
};
