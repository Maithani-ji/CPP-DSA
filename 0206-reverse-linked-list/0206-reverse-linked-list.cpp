/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *//*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize three pointers: p (previous), c (current), and n (next)
        ListNode *p, *c, *n;
        p = NULL; // Initialize p to NULL to mark the end of the reversed list
        c = head; // Initialize c as the current head of the list

        while (c) {
            n = c->next; // Store the next node in n (to avoid losing the reference)
            c->next = p; // Reverse the current node's next pointer to point to the previous node

            // Move p, c, and n pointers forward in the list
            p = c;
            c = n;
        }

        // After the loop, p will be pointing to the new head of the reversed list
        return p;
    }
};
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Check if the list is empty or has only one element
        if (!head || !head->next) {
            return head; // If so, return the current head (no change needed)
        }

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse the current pair of nodes (head and head->next)
        head->next->next = head; // Point head->next's next to the current head, reversing the link
        head->next = NULL; // Set the current head's next pointer to NULL

        return newHead; // Return the new head of the reversed list
    }
};
