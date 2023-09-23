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
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node.
        node->val = node->next->val;
        
        // Update the next pointer to skip the next node, effectively deleting it.
        node->next = node->next->next;
    }
};
/*Here's a brief explanation of the approach:

Copy the value of the next node (node->next->val) into the current node (node->val).
Update the next pointer of the current node (node->next) to skip the next node and point to the node after the one being deleted (node->next->next).*/