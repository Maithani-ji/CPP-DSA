// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;            // Initialize the start of the search range.
        int e = n;            // Initialize the end of the search range.
        int bv = -1;          // Initialize the bad version as -1 (indicating not found yet).

        while (s <= e) {
            int mid = s + (e - s) / 2;  // Calculate the middle version number.

            if (isBadVersion(mid)) {
                bv = mid;        // If the current version is bad, update the bad version and search in the left half.
                e = mid - 1;
            } else {
                s = mid + 1;      // If the current version is not bad, search in the right half.
            }
        }

        return bv;  // Return the bad version found, or -1 if no bad version is found.
    }
};
