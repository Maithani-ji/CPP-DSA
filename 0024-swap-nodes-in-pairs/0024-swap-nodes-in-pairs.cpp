class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head; // Set dummy's next to the head of the list
        ListNode* prev = dummy; // Initialize prev pointer
        
        while (head && head->next) { // While there are at least two nodes to swap
            // Nodes to be swapped
            ListNode* first = head;
            ListNode* second = head->next;
            
            // Swapping
            prev->next = second; // Connect the previous node to the second node
            first->next = second->next; // Connect the first node to the node after the second
            second->next = first; // Connect the second node to the first
            
            // Move to the next pair
            prev = first; // Update prev to the first node of the next pair
            head = first->next; // Update head to the head of the next pair
        }
        
        // Clean up and return the new head
        ListNode* newHead = dummy->next; // Get the new head after swapping
        delete dummy; // Clean up the dummy node
        return newHead; // Return the new head of the list
    }
};
