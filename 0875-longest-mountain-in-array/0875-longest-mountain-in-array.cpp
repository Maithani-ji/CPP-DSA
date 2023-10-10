class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // Check if the array has fewer than 3 elements, which makes it impossible to have a mountain.
        if (arr.size() < 3) {
            return 0;
        }

        int n = arr.size(); // Get the size of the input array 'arr'.
        int mx = 0; // Initialize a variable to store the length of the longest mountain found.

        for (int i = 1; i < n - 1; i++) {
            // Check if the current element is a peak (larger than its neighbors).
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int count = 1; // Initialize a counter to keep track of the mountain's length.
                int j = i; // Initialize a pointer 'j' to explore both sides of the mountain.

                // Count the increasing part of the mountain (uphill).
                while (j > 0 && arr[j] > arr[j - 1]) {
                    j--;
                    count++;
                }

                // Count the decreasing part of the mountain (downhill).
                while (i < n - 1 && arr[i] > arr[i + 1]) {
                    i++;
                    count++;
                }

                mx = max(mx, count); // Update the maximum mountain length found so far.
            }
        }

        return mx; // Return the length of the longest mountain found in the array.
    }
};


/*class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // If the array has less than 3 elements, it's not possible to have a mountain.
        if (arr.size() < 3) {
            return 0;
        }
        
        int count;  // Initialize a counter to keep track of the length of the current mountain.
        int mx = 0; // Initialize a variable to store the length of the longest mountain found so far.
        int n = arr.size(); // Get the size of the input array 'arr'.

        for (int i = 1; i < n; i++) {
            int j = i; // Initialize a pointer 'j' to iterate through the array.
            count = 1; // Initialize the count to 1, considering the current element as the start of a potential mountain.
            bool flag = false; // Initialize a flag to indicate if the mountain is valid.

            // Count the increasing part of the mountain (uphill).
            while (j < n && arr[j] > arr[j - 1]) {
                j++;
                count++;
            }

            // Count the decreasing part of the mountain (downhill).
            while (i != j && j < n && arr[j] < arr[j - 1]) {
                j++;
                count++;
                flag = true; // Set the flag if both uphill and downhill slopes are present.
            }

            if (i != j && flag) {
                mx = max(count, mx); // Update the maximum mountain length.
            }
        }

        return mx; // Return the length of the longest mountain found in the array.
    }
};
*/