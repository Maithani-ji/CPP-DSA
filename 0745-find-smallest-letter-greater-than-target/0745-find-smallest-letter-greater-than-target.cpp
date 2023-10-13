class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();      // Get the number of elements in the 'letters' array.
        int s = 0;                   // Initialize the start index for binary search.
        int e = n - 1;               // Initialize the end index for binary search.


      
        int i = -1;                   // Initialize 'i' to -1 to track the index of the next greatest letter.
        while (s <= e) {
            int mid = s + (e - s) / 2;  // Calculate the middle index for binary search.

            if (letters[mid] > target) {
                i = mid;              // Update 'i' when a letter greater than 'target' is found.
                e = mid - 1;          // Adjust the end index for the left subarray.
            } else {
                s = mid + 1;          // Move the start index to the right subarray.
            }
        }

        // Check if a greater letter was found. If not, return the first letter; otherwise, return the next greatest letter.
        return (i == -1) ? letters[0] : letters[i];
    }
};
