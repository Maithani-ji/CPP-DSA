/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums; // To store the values of nodes from the linked list
        stack<int> s;     // To keep track of indices of elements in 'nums'

        ListNode* temp = head;
        while (temp) {
            nums.push_back(temp->val); // Populate 'nums' with node values
            temp = temp->next;
        }

        vector<int> ans(nums.size()); // Initialize the result vector

        for (int i = 0; i < nums.size(); i++) {
            // While the stack is not empty and the current value is greater than the value at the index on the top of the stack
            while (!s.empty() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i]; // Set the result for the index at the top of the stack
                s.pop(); // Pop the index from the stack
            }
            s.push(i); // Push the current index onto the stack
        }

        return ans; // Return the vector with next larger node values
    }
};
