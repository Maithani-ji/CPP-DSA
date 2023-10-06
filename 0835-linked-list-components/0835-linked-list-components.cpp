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
    // Function to count the number of components in a linked list
    int numComponents(ListNode* head, vector<int>& nums) {
      
        // Create a set to store the values from the 'nums' vector for quick lookup
      
         unordered_set<int> s(nums.begin(), nums.end()); // Use unordered_set for O(1) lookup
      

        bool flag = false; // A flag to indicate if we are inside a component
        int count = 0;     // Initialize the count of components to zero

        // Traverse the linked list
        while (head) {

            if (s.count(head->val) && !flag) {

                flag = true; // Start of a new component
                count++;     // Increment the component count
            }
             else if (!s.count(head->val))
            {
                flag = false; // End of the current component
            }

            head = head->next; // Move to the next node in the linked list
        }

        return count; // Return the total number of components
    }
};
