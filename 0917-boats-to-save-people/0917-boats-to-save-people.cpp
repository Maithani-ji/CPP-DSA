class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people array in ascending order to optimize the boat allocation
        sort(people.begin(), people.end());

        int count = 0;        // Initialize a counter to keep track of the number of boats used
        int i = 0;            // Pointer to the lightest person
        int j = people.size() - 1;  // Pointer to the heaviest person

        // Use a two-pointer approach to allocate people to boats efficiently
        while (i <= j) {
            // Check if the sum of the weights of the lightest and heaviest person is within the limit
            if (people[i] + people[j] <= limit) {
                i++;  // Move to the next lightest person
                j--;  // Move to the next heaviest person
            } else {
                j--;  // If the sum exceeds the limit, only the heaviest person can go in the boat
            }
            count++;  // Increment the boat count after each allocation
        }
        
        return count;  // Return the total number of boats used
    }
};
