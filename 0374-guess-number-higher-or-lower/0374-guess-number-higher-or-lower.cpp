/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 1;        // Initialize the start of the search range.
        int e = n;        // Initialize the end of the search range.

        while (s <= e) {
            int mid = s + (e - s) / 2;  // Calculate the middle number within the range.
            int g = guess(mid);        // Use the guess function to determine if the guess is correct.

            if (g == -1) {
                e = mid - 1;  // Adjust the end of the range if the guess is too high.
            } else if (g == 1) {
                s = mid + 1;  // Adjust the start of the range if the guess is too low.
            } else if (g == 0) {
                return mid;   // Return the correct guess if it matches the target number.
            }
        }

        return 0;  // Return 0 if no guess matches the target (optional).
    }
};
