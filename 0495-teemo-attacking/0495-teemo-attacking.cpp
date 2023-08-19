class Solution {
public:
    int findPoisonedDuration(vector<int>& arr, int duration) {
        // Initialize a variable to keep track of the total poisoned time.
        int totaltime = 0;

        // Iterate through the array of attack times.
        // We start from index 1 to calculate time gaps between consecutive attacks.
        for (int i = 1; i < arr.size(); i++) {
            // Calculate the time gap between the current attack and the previous attack.
            int time_gap = arr[i] - arr[i - 1];

            // Calculate the time poisoned based on the minimum of the time gap and the given duration.
            // This ensures that we account for the poison effect accurately.
            totaltime += min(duration, time_gap);
        }

        // Add the poison duration of the last attack to the total poisoned time.
        totaltime += duration;

        // Return the final total poisoned time.
        return totaltime;
    }
};
