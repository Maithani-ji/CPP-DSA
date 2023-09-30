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
    ListNode* partition(ListNode* head, int x) {
        // Create two new linked lists for smaller and larger values
        ListNode* smallh = new ListNode(0); // Head of smaller values list
        ListNode* largeh = new ListNode(0); // Head of larger values list

        ListNode* small; // Pointer for smaller values list
        ListNode* large; // Pointer for larger values list

        small = smallh; // Initialize small pointer
        large = largeh; // Initialize large pointer

        // Traverse the original linked list
        while (head) {
            if (head->val < x) {
                // If the value is smaller than x, add it to the smaller values list
                small->next = head;
                small = small->next;
            } else {
                // If the value is larger or equal to x, add it to the larger values list
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        // Terminate the larger values list
        large->next = nullptr;

        // Connect the smaller values list to the larger values list
        small->next = largeh->next;

        // Return the head of the combined list
        return smallh->next;
    }
};
