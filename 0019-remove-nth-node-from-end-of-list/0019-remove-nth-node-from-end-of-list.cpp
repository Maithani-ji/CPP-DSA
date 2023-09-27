class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head; // Initialize a fast pointer
        ListNode *slow = head; // Initialize a slow pointer

        // Move the fast pointer 'n' nodes ahead
        while (n--) {
            fast = fast->next;
        }

        // If fast pointer becomes NULL, it means 'n' is equal to the length of the list
        if (!fast) {
            return slow->next; // Remove the head node
        }

        // Move both pointers until the fast pointer reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return head; // Return the updated head of the list
    }
};
