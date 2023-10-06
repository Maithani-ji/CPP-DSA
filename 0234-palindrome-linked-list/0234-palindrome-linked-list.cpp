// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {//brute force using reversing of whole list;
// public:
//     // Function to reverse a linked list
//     ListNode* reverse(ListNode* list) {
//         ListNode* curr;
//         ListNode* prev;
//         ListNode* next;
//         curr = list;
//         prev = NULL;

//         while (curr) {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev; // Return the reversed list
//     }

//     // Function to check if a linked list is a palindrome
//     bool isPalindrome(ListNode* head) {
//         ListNode* a = head;          // Pointer to the original list
//         ListNode* b = reverse(head); // Pointer to the reversed list

//         while (a && b) {
//             if (a->val != b->val) {
//                 return false; // If values don't match, it's not a palindrome
//             }
//             a = a->next;
//             b = b->next;
//         }
//         return true; // If we reach here, the list is a palindrome
//     }
// };

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
    // Function to reverse a linked list
    ListNode* reverse(ListNode* list) {
        ListNode* curr;
        ListNode* prev;
        ListNode* next;
        curr = list;
        prev = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // Return the reversed list
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the linked list using the slow and fast pointer technique
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* revSlow = reverse(slow);

        // Compare the first half (head to slow) with the reversed second half (revSlow to nullptr)
        while (revSlow && head) {
            if (revSlow->val != head->val) {
                return false; // If values don't match, it's not a palindrome
            }
            revSlow = revSlow->next;
            head = head->next;
        }
        return true; // If we reach here, the list is a palindrome
    }
};
