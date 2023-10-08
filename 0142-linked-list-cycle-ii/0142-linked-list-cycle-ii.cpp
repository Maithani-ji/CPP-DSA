class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = head; // Initialize the slow pointer to the head of the linked list
        fast = head; // Initialize the fast pointer to the head of the linked list

        while (fast && fast->next) {
            slow = slow->next; // Move the slow pointer one step
            fast = fast->next->next; // Move the fast pointer two steps

            if (slow == fast) { // If they meet (a cycle is detected)
                slow = head; // Reset the slow pointer to the head of the linked list

                // Find the node where the cycle begins
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // Return the starting node of the cycle
            }
        }

        return nullptr; // No cycle found in the linked list
    }
};
/*class Solution {//brute force
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* current = head;
        while (current) {
            if (visited.count(current)) {
                return current; // Found a cycle
            }
            visited.insert(current);
            current = current->next;
        }

        return nullptr; // No cycle found
    }
};*/
