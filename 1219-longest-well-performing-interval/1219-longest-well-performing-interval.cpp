class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> mp; // Create a hash map to store cumulative scores and their corresponding indices.

        int mx = 0; // Initialize the maximum length of subarray.
        int ans = 0; // Initialize the cumulative score.

        for (int i = 0; i < hours.size(); i++) {
            ans += hours[i] > 8 ? 1 : -1; // Calculate the cumulative score, treating hours greater than 8 as 1, and others as -1.

            if (ans > 0) {
                mx = i + 1; // If the cumulative score is positive, the entire subarray up to index 'i' is a candidate for the result.
            } else {
                if (mp.find(ans) == mp.end()) {
                    mp[ans] = i; // Store the first occurrence of the cumulative score in the hash map.
                }

                if (mp.find(ans - 1) != mp.end()) {
                    mx = max(mx, i - mp[ans - 1]); // Check if there's a cumulative score one less than the current, and update the maximum length if found.
                }
            }
        }
        return mx; // Return the maximum length of the subarray with a positive score.
    }
};
