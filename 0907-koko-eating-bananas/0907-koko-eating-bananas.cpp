class Solution {
public:
    // Helper function to calculate the total hours required to eat all piles at a given speed.
    int64_t findhours(vector<int> piles, int perhour) {
        int64_t totalhour = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            // Calculate the hours needed to eat the current pile and round up using ceil.
            totalhour += ceil((double)piles[i] / (double)perhour);
        }
        return totalhour;
    }

    // Main function to find the minimum eating speed to eat all piles within 'h' hours.
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int64_t e = *max_element(piles.begin(), piles.end()); // Initialize 'e' with the maximum pile size.

        while (s <= e) {
            int mid = s + (e - s) / 2;

            int64_t hours = findhours(piles, mid);  // Calculate the total hours required at the current speed.

            if (hours <= h) {
                e = mid - 1;  // If it's possible to eat all piles in 'h' hours, decrease speed.
            } else {
                s = mid + 1;  // If not, increase speed.
            }
        }

        return s;  // Return the minimum eating speed.
    }
};
