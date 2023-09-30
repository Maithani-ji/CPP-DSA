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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0); // Create a dummy node as the new head
        dummy->next = head; // Point the dummy node to the original head
        ListNode *curr = head; // Initialize a pointer to the current node
        ListNode *prepre = dummy; // Initialize a pointer to the node before the sublist

        // Move the prepre and curr pointers to the appropriate positions
        for (int i = 1; i < left; i++) {
            prepre = prepre->next;
            curr = curr->next;
        }
        
        ListNode *sub = curr; // Pointer to the first node of the sublist
        ListNode *prev = NULL; // Initialize a pointer to the previous node as NULL

        // Reverse the sublist between left and right
        for (int i = 0; i <= right - left; i++) {
            ListNode *next = curr->next; // Save the next node
            curr->next = prev; // Reverse the link direction
            prev = curr; // Move prev to the current node
            curr = next; // Move curr to the next node
        }

        sub->next = curr; // Connect the first node of the sublist to the node after the reversed sublist
        prepre->next = prev; // Connect the node before the sublist to the new sublist head (prev)
        
        return dummy->next; // Return the updated head of the linked list
    }
};
