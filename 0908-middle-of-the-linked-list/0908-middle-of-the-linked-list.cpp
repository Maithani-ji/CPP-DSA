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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow pointer one step and fast pointer two steps
        // When fast pointer reaches the end, slow pointer will be at the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int l = 0; // Initialize a variable to count the number of nodes in the list
        ListNode* temp = head; // Create a temporary pointer to traverse the list
        
        // Calculate the length of the linked list
        while (temp) {
            l++;
            temp = temp->next;
        }

        // Calculate the position of the middle node based on the length
        l = l/2;// go to mid of length
        // Traverse to the middle node
        while (l) {
            head = head->next;
            l--;
        }
        
        return head; // Return the middle node of the linked list
    }
};
*/