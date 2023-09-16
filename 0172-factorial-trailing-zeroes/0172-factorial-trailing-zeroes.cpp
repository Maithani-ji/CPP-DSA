class Solution {// optimal approach // brute approach includes TLE by fiding factorial of a number and counting 0's from behind 
public:
    int trailingZeroes(int n) {
        int c = 0; // Initialize a count variable to keep track of trailing zeros.

        for (int i = 5; i <= n; i *=5) {
            // In this loop, we start from 5 because trailing zeros occur when a number is a multiple of 10,
            // and 10 is the product of 2 and 5. Since even numbers contribute more factors of 2,
            // we focus on counting the factors of 5.
            
            c += n / i;
            // To count the factors of 5 in the range from 1 to n, we divide n by 5, which gives us
            // the count of numbers divisible by 5. However, we need to consider the cases where
            // there are multiple factors of 5, such as 25, 125, and so on. To handle this, we iterate
            // by multiplying 'i' by 5 in each iteration until 'i' becomes greater than 'n'.
        }

        return c; // Return the count of trailing zeros in the factorial of 'n'.
    }
};
