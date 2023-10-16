class Solution {
public:
    int hIndex(vector<int>& cit) {
        int s = 0;               // Initialize the start of the search range.
        int e = cit.size() - 1;  // Initialize the end of the search range.
        int n = cit.size();      // Get the total number of papers in the 'cit' array.
        int mid;                 // Initialize a variable to store the middle index.

        while (s <= e) {         // Perform binary search within the range.
            mid = s + (e - s) / 2;  // Calculate the middle index.

            if (cit[mid] == (n - mid)) {
                // If the number of citations at 'mid' equals the number of papers with more or equal citations,
                // we have found the h-index, so we return it.
                return cit[mid];
            } else if (cit[mid] > (n - mid)) {
                // If the number of citations at 'mid' is greater than the number of papers with more or equal citations,
                // adjust the ending index 'e' to search in the left half.
                e = mid - 1;
            } else {
                // Otherwise, adjust the starting index 's' to search in the right half.
                s = mid + 1;
            }
        }
        
        // If the loop exits and we haven't found the h-index, return 'n - s' as a fallback.
        return n - s;
    }
};
