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
    // Helper function to reverse a linked list.
    ListNode* reverse(ListNode* l) {
        ListNode *curr, *prev, *nxt;

        curr = l;
        prev = NULL;

        // Iterate through the linked list, reversing the direction of pointers.
        while (curr) {
            nxt = curr->next; // Store the next node in 'nxt'.
            curr->next = prev; // Reverse the current node's 'next' pointer to point to 'prev'.
            prev = curr;       // Move 'prev' to the current node.
            curr = nxt;        // Move 'curr' to the next node.
        }

        return prev; // Return the new head after reversing.
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse the input lists to work with the least significant digits first.
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(-1); // Create a dummy node for the result.
        ListNode* temp = dummy; // Initialize a pointer to the current node in the result list.
        int carry = 0; // Initialize the carry to 0.

        // Traverse both input lists and process the digits while considering the carry.
        while (l1 || l2 || carry) {
            int sum = carry; // Initialize the sum with the current carry value.

            if (l1) {
                sum += l1->val; // Add the value of the current node in l1 to the sum.
                l1 = l1->next; // Move to the next node in l1.
            }

            if (l2) {
                sum += l2->val; // Add the value of the current node in l2 to the sum.
                l2 = l2->next; // Move to the next node in l2.
            }

            carry = sum / 10; // Calculate the carry for the next iteration.
            sum %= 10; // Calculate the digit to insert into the result list.

            // Create a new node with the digit and connect it to the result list.
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next; // Move to the next node in the result list.
        }

        // Reverse the result list to obtain the correct order of digits.
        return reverse(dummy->next);
    }
};
