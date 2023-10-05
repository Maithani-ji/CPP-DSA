class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans; // Vector to store the resulting linked lists.
        int size = 0; // Initialize a variable to keep track of the total size of the linked list.
        ListNode* curr = head; // Create a pointer to traverse the linked list.

        // Calculate the total size of the linked list.
        while (curr) {
            curr = curr->next;
            size++;
        }

        int group = size / k; // Calculate the size of each group.
        int extra = size % k; // Calculate the number of extra nodes to distribute among the groups.
        curr = head; // Reset the traversal pointer.
        ListNode* prev = NULL; // Create a pointer to keep track of the previous node.

        // Iterate through the linked list and split it into 'k' parts.
        while (head) {
            ans.push_back(head); // Add the current head of the group to the result vector.
            int g = group; // Initialize the size of the current group.
            
            // Traverse the group and update pointers accordingly.
            while (g && curr) {
                prev = curr;
                curr = curr->next;
                g--;
            }

            // Distribute any extra nodes among the groups.
            if (extra && curr) {
                prev = curr;
                curr = curr->next;
                extra--;
            }

            if (prev) {
                head = curr; // Update the head of the next group.
                prev->next = NULL; // Disconnect the current group from the rest of the list.
            }
        }

        // Add NULL elements to the result vector if 'k' is larger than the number of groups.
        while (ans.size() != k) {
            ans.push_back(NULL);
        }

        return ans; // Return the vector containing the split linked lists.
    }
};
