class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;                  // Initialize the start of the search range.
        int e = arr.size() - 1;     // Initialize the end of the search range.
        
        while (s <= e) {
            int mid = s + (e - s) / 2;  // Calculate the middle index.
            
            if (mid == 0) {
                s++;               // If 'mid' is the first element, adjust the start and continue.
                continue;
            }
            else if (mid == arr.size() - 1) {
                e--;               // If 'mid' is the last element, adjust the end and continue.
                continue;
            }
            
            // Check if the middle element is larger than its neighbors.
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;         // Return the index 'mid' as it's the peak of the mountain.
            } else if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;       // Adjust the start if the middle element is less than its right neighbor and continue.
                continue;
            } else if (arr[mid] < arr[mid - 1]) {
                e = mid - 1;       // Adjust the end if the middle element is less than its left neighbor and continue.
            }
        }
        return 1;                   // Return 1 if no peak is found.
    }
};
