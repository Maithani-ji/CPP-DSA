class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size(); // Get the size of the input string 'dom'.

        // Create arrays to keep track of the distances to the nearest 'R' and 'L' for each position.
        vector<int> r(n, 0); // Initialize 'r' array.
        vector<int> l(n, 0); // Initialize 'l' array.

        int count; // Initialize a counter to keep track of consecutive '.' characters.
        char prev = '.'; // Initialize a variable to keep track of the previous character.

        // Calculate distances to the nearest 'R' on the right side.
        for (int i = 0; i < n; i++) {
            if (dom[i] == 'R') {
                count = 1; // Initialize count to 1, indicating the presence of an 'R'.
                prev = 'R';
            } else if (dom[i] == 'L') {
                prev = 'L';
            }
            if (dom[i] == '.' && prev == 'R') {
                r[i] = count; // Store the distance to the nearest 'R'.
                count++;
            }
        }

        prev = '.';
        // Calculate distances to the nearest 'L' on the left side.
        for (int i = n - 1; i >= 0; i--) {
            if (dom[i] == 'L') {
                count = 1; // Initialize count to 1, indicating the presence of an 'L'.
                prev = 'L';
            } else if (dom[i] == 'R') {
                prev = 'R';
            }
            if (dom[i] == '.' && prev == 'L') {
                l[i] = count; // Store the distance to the nearest 'L'.
                count++;
            }
        }

        // Determine the final state of each position based on the distances to 'R' and 'L'.
        for (int i = 0; i < n; i++) {
            if (r[i] == 0 && l[i] == 0) {
                continue; // Position remains '.', no action needed.
            } else if (r[i] == 0) {
                dom[i] = 'L'; // Position is closer to 'L', set to 'L'.
            } else if (l[i] == 0) {
                dom[i] = 'R'; // Position is closer to 'R', set to 'R'.
            } else if (l[i] == r[i]) {
                dom[i] = '.'; // Equal distances to 'R' and 'L', set to '.'.
            } else if (l[i] > r[i]) {
                dom[i] = 'R'; // Closer to 'L', set to 'R'.
            } else {
                dom[i] = 'L'; // Closer to 'R', set to 'L'.
            }
        }

        return dom; // Return the updated string after applying the dominoes' effects.
    }
};
