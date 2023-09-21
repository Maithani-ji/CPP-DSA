
//This code generates the k-th permutation of numbers from 1 to n. It uses factorials to determine the index of each number in the permutation, removes the used numbers, and constructs the result string accordingly. The loop continues until all numbers are used.
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;
        
        // Initialize a vector 'num' containing numbers from 1 to n.
        for (int i = 1; i < n; i++) {
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);//since we only have to take factorial of 1to n-1 elements since nth is going to get fixed.
        // Adjust k to be zero-based.
        k = k - 1;
        string s;
        
        while (true) {
            // Calculate the index of the selected number.
            int index = k / fact;
            
            // Append the selected number to the result string.
            s += to_string(num[index]);
            
            // Remove the selected number from the vector.
            num.erase(num.begin() + index);
            
            // Check if all numbers have been used.
            if (num.size() == 0) {
                break;
            }
            
            // Update k and fact for the next iteration.
            k = k % fact;
            fact = fact / num.size();
        }
        
        return s;
    }
};

// class Solution {//brute force having n!*n 
// public:
//     vector<string> ans; // Vector to store permutations

//     // Recursive function to generate permutations
//     void generate(string nums, int index) {
//         if (index == nums.size()) { // If the current index reaches the size of the input vector
//             ans.push_back(nums); // Add the current permutation to the result vector
//             return; // Return to backtrack and explore other permutations
//         }

//         for (int i = index; i < nums.size(); i++) { // Iterate through elements starting from the current index
//             swap(nums[i], nums[index]); // Swap the current element with the element at the current index
//             generate(nums, index + 1); // Recursively generate permutations for the remaining elements
//             swap(nums[i], nums[index]); // Swap the elements back for backtracking
//         }
//     }

//     // Function to generate the k-th permutation of numbers from 1 to n
//     string getPermutation(int n, int k) {
//         string s;
//         int i = 1;
//         while (i <= n) {
//             s += to_string(i);
//             i++;
//         }
//         generate(s, 0);
//         sort(ans.begin(),ans.end());//sort it to arrange the answere elements and return k-1th element.
//         string an = ans[k - 1]; // Get the k-th permutation

//         return an;
//     }
// };
