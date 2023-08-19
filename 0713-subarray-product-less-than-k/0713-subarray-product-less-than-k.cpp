class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;      // Left pointer of the sliding window
        int j = 0;      // Right pointer of the sliding window
        int count = 0;  // Count of valid subarrays
        long prod = 1;  // Current product of elements within the sliding window

        while (j < nums.size()) {
            prod = prod * nums[j];  // Multiply the current element into the product

            // If the product becomes greater than or equal to k, adjust the window isng left pointer
            while (i <= j && prod >= k) {
                prod /= nums[i];  // Divide by the left element of the window
                i++;              // Move the left pointer to the right
            }

            // If the product is less than k, then all subarrays ending at j are valid
            if (prod < k) {
                count += j - i + 1;  // Count the valid subarrays
            }

            j++;  // Move the right pointer to the right
        }

        return count;
    }
};
