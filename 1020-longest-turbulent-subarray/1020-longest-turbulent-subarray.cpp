class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // Initialize variables for increasing and decreasing subarray lengths,
        // and a variable to keep track of the maximum turbulent subarray length.
        int inc = 1;  // Length of current increasing subarray
        int dec = 1;  // Length of current decreasing subarray
        int count = 1; // Maximum turbulent subarray length
                       //Using count as 1 instead of 0 is an initialization choice that ensures that even if the array has only 
                       //one element, that element is considered as a valid turbulent subarray of length 1. In the problem 
                       //statement, it's mentioned that a subarray with a single element is considered turbulent.
        
        // Iterate through the array starting from the second element.
        for (int i = 1; i < arr.size(); i++) {
            // Compare the current element with the previous one.// and use previous inc dec to store zig zag pattern length.
            if (arr[i] > arr[i - 1]) {
                // If current > previous, it's part of an increasing sequence.
                // Increment the increasing subarray length using prev decrease and reset the decreasing length.
                inc = dec + 1;
                dec = 1;
            } else if (arr[i] < arr[i - 1]) {
                // If current < previous, it's part of a decreasing sequence.
                // Increment the decreasing subarray length using previous increasing and reset the increasing length.
                dec = inc + 1;
                inc = 1;
            } else {
                // If current == previous, start new sequences for both increasing and decreasing.
                inc = 1;
                dec = 1;
            }
            
            // Update the maximum turbulent subarray length considering the lengths of the current subarrays.
            count = max(count, max(inc, dec));
        }
        
        // Return the maximum turbulent subarray length.
        return count;
    }
};
