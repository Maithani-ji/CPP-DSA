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
class Solution {//optimal soln  --> brute will be loop k times and always make the last first .
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Check for base cases:
        // If the list is empty, has only one node, or k is 0, no rotation is needed.
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Initialize a temporary pointer to traverse the list and calculate its length.
        ListNode* temp = head;
        int length = 0;

        // Traverse the list to find its length and make it circular by connecting the last node to the head.
        while (temp) {
            if (temp->next == NULL) {
                temp->next = head; // Make it circular
                length++; // Increment the length
                break;
            }
            length++; // Increment the length
            temp = temp->next; // Move to the next node
        }

        // Calculate the effective rotation count by taking the remainder when k is divided by the length.
        k = k % length;

        // Calculate the position from which to rotate by subtracting k from (length - 1).
        k = length - 1-k;

        // Reset the temporary pointer to the head.
        temp = head;

        // Move the temporary pointer to the node just before the new head after rotation.
        while (k--) {
            temp = temp->next;
        }

        // Update the 'head' pointer to the new head after rotation and break the circular structure.
        head = temp->next;
        temp->next = NULL;

        // Return the updated head, which is the new head after rotation.
        return head;
    }
};
