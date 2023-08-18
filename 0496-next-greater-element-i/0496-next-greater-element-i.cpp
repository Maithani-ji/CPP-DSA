class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st; // Initialize a stack to keep track of elements in nums2
        unordered_map<int, int> mp; // Initialize a map to store next greater element mapping

        // Iterate through nums2 to find the next greater element for each element
        for (auto num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num; // Store the mapping of next greater element
                st.pop(); // Pop smaller elements from the stack
            }
            st.push(num); // Push the current element onto the stack
        }

        vector<int> ans; // Initialize a vector to store the results

        // Iterate through nums1 to get the next greater elements from the map
        for (auto num : nums1) {
            ans.push_back((mp.count(num) ? mp[num] : -1)); // Push the next greater element or -1 if not found
        }

        return ans; // Return the vector containing the next greater elements for nums1
    }
};

// use stack and     queues



// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result; // Store the next greater elements
        
//         for (int num : nums1) { // Iterate through each element in nums1
//             int index = -1; // Initialize index to -1
            
//             // Find the index of num in nums2
//             for (int i = 0; i < nums2.size(); ++i) {
//                 if (nums2[i] == num) {
//                     index = i; // Store the index where num is found in nums2
//                     break;
//                 }
//             }
            
//             int nextGreater = -1; // Initialize nextGreater to -1
            
//             // Iterate through nums2 starting from index + 1 to find the next greater element
//             for (int i = index + 1; i < nums2.size(); ++i) {
//                 if (nums2[i] > num) {
//                     nextGreater = nums2[i]; // Store the first element greater than num
//                     break;
//                 }
//             }
            
//             result.push_back(nextGreater); // Add the next greater element (or -1) to the result vector
//         }
        
//         return result; // Return the vector containing next greater elements for each num in nums1
//     }
// };
