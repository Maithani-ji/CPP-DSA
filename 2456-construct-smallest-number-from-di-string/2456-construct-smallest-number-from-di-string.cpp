
class Solution {//using stack
public:
string smallestNumber(string pattern) {//easy to implement without using reverse or array.
    string result; // Initialize the string to store the result
    stack<int> s; // Initialize a stack to keep track of numbers

    // Loop through each index (including an extra iteration for the end)
    for (int i = 0; i <= pattern.length(); i++) {
        s.push(i + 1); // Push the current number onto the stack

        // If the end of the pattern is reached or "I" is encountered
        if (i == pattern.length() || pattern[i] == 'I') {
            // Pop numbers from the stack and append to the result
            while (!s.empty()) {
                result += to_string(s.top()); // Convert the top of the stack to a string and add to result
                s.pop(); // Remove the element from the stack
            }
        }
    }

    return result; // Return the final result string
}
};

/*class Solution {//without using stack
public:
    string smallestNumber(string pattern) {
        int n = pattern.size() + 1; // Calculate the length of the pattern plus 1
        vector<int> arr(n); // Create an array to store the numbers

        // Step 1: Fill the array with initial values 1 to n
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1; // Initialize the array elements in increasing order
        }

        // Step 2: Process the pattern and reverse portions of the array
        for (int i = 0; i < n; i++) {
            int temp = i; // Initialize a temporary index

            // Find the end of a decreasing sequence in the pattern
            while (temp < n - 1 && pattern[temp] == 'D') {
                temp++; // Move the temporary index forward
            }

            // Reverse the portion of the array between indices i and temp
            reverse(arr.begin() + i, arr.begin() + temp + 1);

            // Adjust the loop index if a decreasing sequence was encountered
            if (temp != i) {
                i = temp - 1; // Move the index back to the last element of the reversed sequence
            }
        }

        // Step 3: Convert the array elements to strings and concatenate them
        string ans; // Initialize the resulting string
        for (int i = 0; i < n; i++) {
            ans += to_string(arr[i]); // Convert the array element to a string and append to ans
        }

        // Step 4: Return the resulting string
        return ans; // Return the smallest number following the pattern
    }
};
*/