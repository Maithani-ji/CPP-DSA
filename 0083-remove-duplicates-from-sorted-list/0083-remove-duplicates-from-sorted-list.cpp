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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head; // Return if the list is empty or has only one node
        }

        ListNode* current = head; // Initialize a pointer to traverse the list

        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode* temp = current->next; // Store a pointer to the duplicate node
                current->next = temp->next; // Update the next pointer to skip the duplicate node
                delete temp; // Free memory of the duplicate node
            } else {
                current = current->next; // Move to the next node if no duplicate is found
            }
        }

        return head; // Return the modified linked list without duplicates
    }
};
