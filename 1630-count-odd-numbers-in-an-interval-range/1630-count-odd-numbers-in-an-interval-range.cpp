
//Initialize low with 5 and high with 15.

//Calculate the count of odd numbers within the range using the formula:  (high + 1) / 2 - (low / 2)
/*
high + 1 is 16.
(high + 1) / 2 is 8. This is the count of both odd and even numbers from 1 to 15.
Now, let's calculate the count of even numbers from 1 to 4 (inclusive), which we will subtract from the total count:

low / 2 is 2. This is the count of both odd and even numbers from 1 to 4.
Subtract the count of even numbers (low / 2) from the total count of numbers ((high + 1) / 2) to get the count of odd numbers within the range: ie 8-2= 6 is the no of off element between 5 and 15
*/
class Solution {//optimal
public:
    int countOdds(int low, int high) {
        // Calculate the count of odd numbers within the range [low, high]
        // Note: If both low and high are odd, we have an extra odd number
        int count = (high + 1) / 2 - (low / 2);
        return count;
    }
};

// class Solution {//brute force 
// public:
//     // Recursive function to count odd numbers within a given range
//     int count(int low, int high, int c = 0) {
//         // Base case: If the lower bound exceeds the upper bound, return the count
//         if (low > high) {
//             return c;
//         }

//         // Check if the current number (low) is odd
//         if (low % 2 == 1) {
//             // Increment the count if it's odd
//             c++;
//         }

//         // Recursively call the function with the next number and the same count
//         return count(low + 1, high, c);
//     }

//     // Public function to count odd numbers within a range
//     int countOdds(int low, int high) {
//         // Call the recursive count function with the specified range
//         return count(low, high);
//     }
// };

