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
        // Create a dummy node to simplify edge cases.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Traverse the list while checking for duplicates.
        while (head && head->next) {
            if (head->val != head->next->val) {
                prev = prev->next; // Move the previous pointer.
            } else {
                // Skip all duplicate nodes.
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // Remove duplicates.
            }
            head = head->next;
        }

        // Clean up and return the updated list.
        head = dummy->next;
        delete dummy;
        return head;
    }
};
