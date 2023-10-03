/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;           // Value of the current node.
 *     ListNode *next;    // Pointer to the next node in the list.
 *     ListNode() : val(0), next(nullptr) {}               // Default constructor.
 *     ListNode(int x) : val(x), next(nullptr) {}          // Constructor with value.
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node pointer.
 * };
 */
class Solution {
public:
    // Helper function to merge two sorted linked lists.
    ListNode* merge(ListNode* slow, ListNode* fast) {
        if (!slow) {
            return fast; // If one list is empty, return the other list.
        } else if (!fast) {
            return slow;
        }

        ListNode* head = new ListNode(); // Create a dummy node for the merged list.
        ListNode* dummy = head; // Maintain a pointer to the head of the merged list.

        while (slow && fast) {
            if (slow->val < fast->val) {
                dummy->next = slow; // Connect the current node from the 'slow' list.
                slow = slow->next; // Move the 'slow' pointer to the next node.
            } else {
                dummy->next = fast; // Connect the current node from the 'fast' list.
                fast = fast->next; // Move the 'fast' pointer to the next node.
            }
            dummy = dummy->next; // Move the merged list pointer.
        }

        // Handle any remaining nodes in either list.
        while (slow) {
            dummy->next = slow;
            slow = slow->next;
            dummy = dummy->next;
        }
        while (fast) {
            dummy->next = fast;
            fast = fast->next;
            dummy = dummy->next;
        }

        return head->next; // Return the merged list.
    }

    // Main function for sorting a linked list using merge sort.
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: empty list or single node is already sorted.
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Use the slow and fast pointer technique to split the list into two halves.
        while (fast && fast->next) {
            slow = slow->next; // Move 'slow' by one step.
            fast = fast->next->next; // Move 'fast' by two steps.
        }

        fast = slow->next; // 'fast' is the start of the second half.
        slow->next = nullptr; // Break the link between the two halves.

        // Recursively sort both halves.
        slow = sortList(head); // Sort the first half.
        fast = sortList(fast); // Sort the second half.

        // Merge the sorted halves to obtain the final sorted list.
        return merge(slow, fast);
    }
};
