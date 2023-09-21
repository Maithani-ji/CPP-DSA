class Solution {
public:
    vector<string> ans; // Vector to store valid time combinations
    
    // Arrays to store possible hours and minutes represented as binary bits
    vector<int> hours = {1, 2, 4, 8};
    vector<int> minutes = {1, 2, 4, 8, 16, 32};

    // Recursive function to generate valid time combinations
    void generate(int turnedOn, int hour, int minute, int index) {
        // If no more LEDs are left to be turned on, check if the time is valid
        if (turnedOn == 0) {
            if (hour < 12 && minute < 60) {
                // Format the time string with leading zeros if necessary and add it to 'ans'
                ans.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
            }
            return;
        }

        // Try turning on LEDs (hours or minutes) starting from the given index
        for (int i = index; i < hours.size() + minutes.size(); i++) {
            if (i < hours.size()) {
                // Try turning on an hour LED
                generate(turnedOn - 1, hour + hours[i], minute, i + 1);
            } else {
                // Try turning on a minute LED
                generate(turnedOn - 1, hour, minute + minutes[i - hours.size()], i + 1);
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        generate(turnedOn, 0, 0, 0); // Start generating valid combinations
        return ans; // Return the vector containing valid time strings
    }
};
