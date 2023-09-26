/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        // Find the tail node of list A and make it cyclic
        ListNode *tail = A;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = A;

        // Initialize two pointers, fast and slow, in list B
        ListNode *fast = B;
        ListNode *slow = B;

        // Detect the intersection point using Floyd's cycle detection algorithm
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            // When they meet, reset one pointer to the head of list B
            if (fast == slow) {
                slow = B;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // Restore the original state by breaking the cycle
                tail->next = NULL;
                return slow; // Return the intersection node
            }
        }

        // Restore the original state by breaking the cycle
        tail->next = NULL;

        return NULL; // Return NULL if there's no intersection
    }
};
*/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Check if either of the input lists is empty; if so, there's no intersection
        if (!headA || !headB) return NULL;

        ListNode *ptrA = headA; // Initialize a pointer for list A
        ListNode *ptrB = headB; // Initialize a pointer for list B

        // Traverse both lists until an intersection is found or both reach the end
        while (ptrA != ptrB) {
            // Move ptrA and ptrB to the next node in their respective lists
            ptrA = (ptrA) ? ptrA->next : headB;
            ptrB = (ptrB) ? ptrB->next : headA;
        }

        // Return the intersection node if found, or NULL if there's no intersection
        return ptrA;
    }
};
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *//*
class Solution {
public:
    // Helper function to calculate the length of a linked list
    int size(ListNode *head) {
        int i = 0;
        while (head) {
            i++;
            head = head->next;
        }
        return i;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Calculate the lengths of both linked lists
        int a = size(headA);
        int b = size(headB);

        // Check if either of the input lists is empty; if so, there's no intersection
        if (!headA || !headB) return NULL;

        // Adjust the starting positions of headA and headB if they have different lengths
        while (a > b) {
            headA = headA->next;
            a--;
        }
        while (b > a) {
            headB = headB->next;
            b--;
        }

        // Traverse both lists in parallel until an intersection is found or both reach the end
        while (headA && headB) {
            if (headA == headB) return headA; // If the nodes are the same, it's the intersection
            headA = headA->next;
            headB = headB->next;
        }

        return NULL; // Return NULL if there's no intersection
    }
};
*/