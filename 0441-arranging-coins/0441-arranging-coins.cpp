class Solution {
public:
    int arrangeCoins(int n) {
        int s = 1;                 // Initialize the start of the search range.
        int e = n;                 // Initialize the end of the search range.

        while (s <= e) {
            int mid = s + (e - s) / 2;  // Calculate the middle number within the range.

            long long k = static_cast<long long>(mid) * (mid + 1) / 2;  // Calculate the sum of the first 'mid' natural numbers.

            if (k == n) {
                return mid;  // If the sum matches 'n,' return 'mid' as it represents the maximum number of full rows.
            } else if (k < n) {
                s = mid + 1;   // Adjust the start of the range if the sum is less than 'n.'
            } else {
                e = mid - 1;   // Adjust the end of the range if the sum is greater than 'n.'
            }
        }
        return e;  // Return 'e' as it represents the maximum number of full rows of coins that can be arranged within 'n' coins.
    }
};

// or just use 
// class Solution {// mThematical formula after deriving it from  k*(k+1)/2 <= n
// public:
//     int arrangeCoins(int n) {
// return (int)(sqrt(2*long(n)+0.25)-0.5);
// }
// };