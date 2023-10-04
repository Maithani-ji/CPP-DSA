class Solution {
public:
    // Helper function to reverse 'k' nodes in a group.
    ListNode* reverse(ListNode* head, int k, int size) {
        // If the remaining group size is less than 'k', no reversal needed.
        if (size < k) {
            return head;
        }
        // If the linked list is empty, return it as is.
        if (!head) {
            return head;
        }
        
        ListNode *curr, *nxt, *prev;
        curr = head;
        prev = nullptr;
        int kk = 0;
        
        // Reverse 'k' nodes in the current group.
        while (curr && kk < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            kk++;
        }
       
        // Link the reversed group to the next group.
        head->next = reverse(nxt, k, size - k);
     
        return prev; // Return the new head of the reversed group.
    }
    
    // Main function to reverse the linked list in groups of size 'k'.
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        
        // Calculate the size of the linked list.
        while (temp) {
            size++;
            temp = temp->next;
        }
        
        // Start the reversal process.
        return reverse(head, k, size);
    }
};
