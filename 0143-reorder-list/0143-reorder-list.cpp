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

    // Helper function to reverse a linked list.
    ListNode* reverse(ListNode *head)
    {
        ListNode* curr = head;  // Current node
        ListNode* prev = NULL;  // Previous node (initialized to NULL)
        ListNode* nxt = NULL;   // Next node

        while (curr)
        {
            nxt = curr->next;  // Store the next node
            curr->next = prev; // Reverse the current node's next pointer
            prev = curr;       // Move the previous pointer to the current node
            curr = nxt;        // Move the current pointer to the next node
        }

        return prev;  // Return the new head of the reversed list
    }

    // Main function to reorder the given linked list.
    void reorderList(ListNode* head) {
        // Find the middle of the linked list using the slow and fast pointers.
        ListNode* slow = head;        // Slow pointer starting from the head
        ListNode* fast = head->next;  // Fast pointer starting from the second node

        while (fast && fast->next)
        {
            slow = slow->next;        // Move the slow pointer one step
            fast = fast->next->next;  // Move the fast pointer two steps
        }

        // Split the linked list into two halves.
        fast = slow->next;  // 'fast' now points to the second half
        slow->next = NULL;  // Terminate the first half by setting 'slow's next to NULL

        // Reverse the second half of the linked list.
        fast = reverse(fast);

        // Merge the two halves to reorder the list.
        slow = head;  // Reset 'slow' to the head of the first half
        while (fast)
        {
            ListNode* temp1 = slow->next;  // Store the next node in the first half
            slow->next = fast;            // Link 'slow' to the current node in the second half
            ListNode* temp2 = fast->next; // Store the next node in the second half
            fast->next = temp1;           // Link the current node in the second half to the first half
            slow = temp1;                 // Move 'slow' one step forward in the first half
            fast = temp2;                 // Move 'fast' one step forward in the second half
        }
    }
};
