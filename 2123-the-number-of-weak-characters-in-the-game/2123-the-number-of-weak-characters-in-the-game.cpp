class Solution {
public:
    // Comparator function for sorting the vector of vectors
    static bool comparator(vector<int>& v1, vector<int>& v2) {
        // Sort by attack (v1[0]) in ascending order
        // If attack is equal, sort by defense (v1[1]) in descending order
        if (v1[0] == v2[0]) {
            return v1[1] > v2[1];
        }
        // Sort by attack (v1[0]) in ascending order
        return v1[0] < v2[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        // Sort the characters in 'prop' based on the custom comparator function
        sort(prop.begin(), prop.end(), comparator);
        stack<pair<int, int>> st; // Stack to track characters' properties
        int count = 0; // Count of weak characters

        // Iterate through each character in 'prop'
        for (auto& c : prop) {
            // Check if the current character is weaker than characters on the stack
            while (!st.empty() && st.top().first < c[0] && st.top().second < c[1]) {
                count++; // Increment count for each weak character found
                st.pop(); // Remove the character from the stack
            }
            st.push(make_pair(c[0], c[1])); // Push the current character onto the stack
        }

        return count; // Return the count of weak characters
    }
};
