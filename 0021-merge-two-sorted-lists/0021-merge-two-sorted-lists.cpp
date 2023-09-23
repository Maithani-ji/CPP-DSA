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

// Create a structure definition for a singly-linked list node
// It contains an integer value (val) and a pointer to the next node (next)
/*
class Solution {
public:
    // Merge two sorted linked lists into one sorted linked list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // Check if l1 is empty
        if (l1 == nullptr) {
            return l2; // Return l2 if l1 is empty because the merged list will be l2
        }
        
        // Check if l2 is empty
        if (l2 == nullptr) {
            return l1; // Return l1 if l2 is empty because the merged list will be l1
        }

        // Compare the values of the current nodes in l1 and l2
        if (l1->val <= l2->val) {
            // If the value in l1 is smaller or equal, it becomes the next node
            // Recursively merge the remaining elements of l1 and all of l2
            l1->next = mergeTwoLists(l1->next, l2);
            return l1; // Return l1 as the new merged list
        }
        else {
            // If the value in l2 is smaller, it becomes the next node
            // Recursively merge the remaining elements of l2 and all of l1
            l2->next = mergeTwoLists(l1, l2->next);
            return l2; // Return l2 as the new merged list
        }
    }
};*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        // If list1 happens to be NULL, we will simply return list2.
        if (list1 == NULL)
            return list2;
        
        // If list2 happens to be NULL, we will simply return list1.
        if (list2 == NULL)
            return list1;
        
        ListNode *ptr = list1;
        
        // Compare the values of the first nodes in list1 and list2
        if (list1->val > list2->val) {
            // If the value in list2 is smaller, make ptr point to list2 and move list2 forward
            ptr = list2;
            list2 = list2->next;
        } else {
            // If the value in list1 is smaller or equal, move list1 forward
            list1 = list1->next;
        }
        
        ListNode *curr = ptr;
        
        // Until one of the lists reaches NULL
        while (list1 && list2) {
            if (list1->val < list2->val) {
                // If the value in list1 is smaller, connect curr to list1 and move list1 forward
                curr->next = list1;
                list1 = list1->next;
            } else {
                // If the value in list2 is smaller or equal, connect curr to list2 and move list2 forward
                curr->next = list2;
                list2 = list2->next;
            }
            // Move curr to the newly connected node
            curr = curr->next;
        }
        
        // Add the remaining elements of the non-empty list to the merged list
        if (!list1)
            curr->next = list2;
        else
            curr->next = list1;
        
        return ptr; // Return the merged list starting from ptr

    }
};
