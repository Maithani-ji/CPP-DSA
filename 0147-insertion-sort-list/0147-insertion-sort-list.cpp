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
    ListNode* insertionSortList(ListNode* head) {
        // Create a dummy node with a high value. This node acts as the sorted list's head.
        ListNode* dumm = new ListNode(1000);

        // Iterate through the original linked list until all nodes are inserted into the sorted list.
        while (head) {
            // Initialize pointers: temp for traversal in sorted list, and next to preserve next node in the original list.
            ListNode* temp = dumm;
            ListNode* next = head->next;
            
            // Find the correct position in the sorted list to insert the current node.
            while (temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }

            // Insert the current node into the sorted list at its correct position.
            head->next = temp->next; // Connect the current node to the next node in the sorted list.
            temp->next = head;       // Connect the previous node to the current node.

            // Move to the next unsorted node in the original list.
            head = next;
        }
        
        // Return the sorted list starting from the next node of the dummy node.
        return dumm->next;
    }
};
