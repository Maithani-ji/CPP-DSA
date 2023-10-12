class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // Create an unordered_map to store the count of each element in 'arr'.
        unordered_map<int, long> mp; // Use 'long' data type for counts to avoid overflow.
        long res = 0; // Initialize the result with a 'long' data type.
        const int mod = 1e9 + 7; // Define the constant modulo value.

        // Count the occurrences of each element in 'arr' and store them in 'mp'.
        for (int i : arr) {
            mp[i]++;
        }

        // Iterate through the elements in 'mp' to find combinations that sum up to 'target'.
        for (auto it1 : mp) {
            for (auto it2 : mp) {
                int num1 = it1.first, num2 = it2.first, num3 = target - num1 - num2;

                if (mp.count(num3)) {
                    // Check for various cases of combinations and calculate their counts.

                    // Case 1: All three elements are the same.
                    if (num1 == num2 && num2 == num3) {
                        res += (mp[num1] * (mp[num1] - 1) * (mp[num1] - 2)) / 6;
                    } 
                    // Case 2: Two elements are the same, one is different.
                    else if (num1 == num2 && num2 != num3) {
                        res += (mp[num1] * (mp[num1] - 1) * mp[num3]) / 2;
                    } 
                    // Case 3: All three elements are different and in increasing order.
                    else if (num1 < num2 && num2 < num3) {
                        res += (mp[num1] * mp[num2] * mp[num3]);
                    }
                }
            }
        }

        return res % mod; // Return the result modulo the constant 'mod'.
    }
};
