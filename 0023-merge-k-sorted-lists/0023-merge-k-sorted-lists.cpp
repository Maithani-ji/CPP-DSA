class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); // Get the number of linked lists in the input vector.

        if (n == 0) {
            return nullptr; // If the input vector is empty, return nullptr.
        }

        ListNode* start = lists[0]; // Initialize the starting pointer with the first linked list.

        for (int i = 1; i < n; i++) {
            ListNode* list1 = start; // Initialize the first linked list with the current merged list.
            ListNode* list2 = lists[i]; // Get the next linked list from the input vector.

            if (!list1) {
                start = list2; // If the first linked list is empty, update the starting pointer to the second list.
                continue;
            }

            if (!list2) {
                continue; // If the second linked list is empty, continue to the next iteration.
            }

            ListNode* ptr;

            if (list1->val > list2->val) {
                ptr = list2; // Select the node with the smaller value as the new merged list node.
                list2 = list2->next; // Move to the next node in the second linked list.
            } else {
                ptr = list1; // Select the node with the smaller or equal value as the new merged list node.
                list1 = list1->next; // Move to the next node in the first linked list.
            }

            ListNode* curr = ptr;

            while (list1 && list2) {
                if (list1->val < list2->val) {
                    curr->next = list1; // Connect the current node to the smaller node from list1.
                    list1 = list1->next; // Move to the next node in list1.
                } else {
                    curr->next = list2; // Connect the current node to the smaller node from list2.
                    list2 = list2->next; // Move to the next node in list2.
                }
                curr = curr->next; // Move to the newly connected node.
            }

            if (!list1) {
                curr->next = list2; // Connect the remaining elements of list2 to the merged list.
            } else {
                curr->next = list1; // Connect the remaining elements of list1 to the merged list.
            }

            start = ptr; // Update the starting pointer to the merged list.
        }

        return start; // Return the merged linked list.
    }
};
