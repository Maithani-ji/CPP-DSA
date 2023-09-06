class Solution {
public:
    // Recursive function for calculating power
    double pow(double x, long nn) {
        // Base case: If the exponent is 0, return 1
        if (nn == 0) {
            return 1;
        }
        // If the exponent is odd, multiply 'x' by the result of the recursive call
        if (nn % 2) {
            return x * pow(x, nn - 1);
        }
        // If the exponent is even, square 'x' and calculate the result of the recursive call
        else {
            return pow(x * x, nn / 2);
        }
    }

    // Function for calculating 'x' raised to the power of 'n'
    double myPow(double x, int n) {
        // Convert 'n' to a long variable to handle potential overflow issues
        long nn = n;
        if (nn < 0) {
            nn = abs(n); // Make 'nn' positive if 'n' is negative
        }

        // Calculate the result using the 'pow' function
        double ans = pow(x, nn);

        // If 'n' was originally negative, take the reciprocal of 'ans'
        if (n < 0) {
            ans = 1.0 / ans; // Return the reciprocal of 'ans' as the result
        }

        return ans;
    }
};



// class Solution {
// public:
//     // Function for calculating 'x' raised to the power of 'n'
//     double myPow(double x, int n) {
//         // Convert 'n' to a long long integer to handle potential overflow issues
//         long long int k = abs(n);
//         double ans = 1.0;

//         // Handle special cases
//         if (n == 0) {
//             return 1.0; // Anything raised to the power of 0 is 1
//         }
//         if (x == 1.0) {
//             return x; // Anything raised to the power of 1 is itself
//         }

//         // Iterate while 'k' is greater than 0
//         while (k > 0) {
//             if (k % 2) {
//                 // If 'k' is odd, multiply 'ans' by 'x' and decrease 'k' by 1
//                 ans = ans * x;
//                 k--;
//             } else {
//                 // If 'k' is even, square 'x' and divide 'k' by 2
//                 x = x * x;
//                 k = k / 2;
//             }
//         }

//         // Handle the case when 'n' is negative
//         if (n < 0) {
//             double p = (double)(1.0) / (double)(ans);
//             return p; // Return the reciprocal of 'ans'
//         }

//         return ans; // Return the calculated result
//     }
// };


// class Solution {// brute force O(n) T-1
//  public:
//     double myPow(double x, int n) {
//         if (n == 0) {
//             return 1.0; // Anything raised to the power of 0 is 1.
//         }

//         double result = 1.0;

//         // Handle negative exponent
//         if (n < 0) {
//             x = 1.0 / x; // Take the reciprocal of 'x'
//             n = -n;      // Make 'n' positive
//         }

//         for (int i = 0; i < n; ++i) {
//             result *= x; // Multiply 'result' by 'x' 'n' times
//         }

//         return result;
//     }
// };
