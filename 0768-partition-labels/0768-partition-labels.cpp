class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Initialize an array to store the last occurrence index of each character
        vector<int> lastOccurrence(26, 0);
        
        // Populate the lastOccurrence array with the maximum index of each character in the string
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        int prev = -1; // Initialize the previous partition's end index
        int maxIndex = INT_MIN; // Initialize the maximum occurrence index within the current partition
        vector<int> partitionLengths; // Store the lengths of partitions

        for (int i = 0; i < s.size(); i++) {
            maxIndex = max(maxIndex, lastOccurrence[s[i] - 'a']); // Update the maximum occurrence index

            // If the current index reaches the maximum occurrence index within the current partition
            if (maxIndex == i) {
                partitionLengths.push_back(maxIndex - prev); // Store the partition length
                prev = maxIndex; // Update the previous partition's end index
            }
        }
        
        return partitionLengths; // Return the lengths of partitions
    }
};

