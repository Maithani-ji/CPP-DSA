class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1;               // Initialize the start of the search range.
        int e = num / 2;         // Initialize the end of the search range.
        if(num<=1) return true; // corner case 
        while (s <=e) {
            int64_t mid = s + (e - s) / 2;  // Calculate the middle number within the range.

            if (mid * mid > num) {
                e = mid - 1;   // Adjust the end of the range if the square of 'mid' is too large.
            } else if (mid * mid < num) {
                s = mid + 1;   // Adjust the start of the range if the square of 'mid' is too small.
            } else if (mid * mid == num) {
                return true;   // Return true if 'mid' squared equals 'num,' indicating a perfect square.
            }
        }

        return false;  // Return false if no perfect square is found in the range.
    }
};
