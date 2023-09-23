/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, i and j, both initially pointing to the head of the linked list.
        ListNode *i, *j;
        i = head;
        j = head;

        // Iterate through the list with two pointers, one moving one step at a time (i) 
        // and the other moving two steps at a time (j).
        while (j && j->next) {
            i = i->next;         // Move i one step
            j = j->next->next;   // Move j two steps

            // If at any point i and j meet (i == j), there is a cycle in the linked list.
            if (i == j) {
                return true;
            }
        }

        // If the loop completes without finding a cycle, there is no cycle in the linked list.
        return false;
    }
};
