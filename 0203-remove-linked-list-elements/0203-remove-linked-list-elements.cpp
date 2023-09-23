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
    ListNode* removeElements(ListNode* head, int val) {
        // Handle cases where the value to be removed is at the beginning of the list
        while (head && head->val == val) {
            ListNode* temp = head; // Store the current head node
            head = head->next; // Move head to the next node
            delete temp; // Free memory of the removed node
        }
        
        ListNode* current = head; // Initialize a pointer for traversing the list
        
        while (current && current->next) {
            if (current->next->val == val) {
                ListNode* temp = current->next; // Store the node to be removed
                current->next = temp->next; // Update the next pointer to skip the removed node
                delete temp; // Free memory of the removed node
            } else {
                current = current->next; // Move to the next node if no match is found
            }
        }
   
        return head; // Return the modified linked list after removal
    }
};
