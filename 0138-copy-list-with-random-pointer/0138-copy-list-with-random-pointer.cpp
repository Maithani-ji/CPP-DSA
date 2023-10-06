/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*class Solution {  // brute force
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Create a mapping between original nodes and their copies
        unordered_map<Node*, Node*> nodeMap;

        // Create a new list and copy the values from the original list
        Node* newHead = new Node(head->val);
        Node* newCurr = newHead;
        Node* curr = head;

        nodeMap[curr] = newCurr;

        while (curr->next) {
            newCurr->next = new Node(curr->next->val);
            newCurr = newCurr->next;
            curr = curr->next;
            nodeMap[curr] = newCurr;
        }

        // Copy random pointers based on the mapping
        curr = head;
        newCurr = newHead;
        while (curr) {
            if (curr->random) {
                newCurr->random = nodeMap[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Initialize current and next pointers to traverse the original list
        Node *curr, *next;
        curr = head;

        // Step 1: Create a copy of each node and insert it immediately after the original node
        while (curr) {
            next = curr->next; // Save the next node in the original list
            Node* copy = new Node(curr->val); // Create a copy of the current node
            curr->next = copy; // Insert the copied node after the current node
            copy->next = next; // Set the copied node's next pointer to the next node in the original list

            curr = next; // Move to the next node in the original list
        }

        // Step 2: Update the random pointers of the copied nodes based on the original nodes' random pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next; // Set the copied node's random pointer
            }

            curr = curr->next->next; // Move to the next original node
        }

        // Step 3: Separate the original list and the copied list
        curr = head;
        Node* dummy = new Node(0); // Create a dummy node to simplify list manipulation
        Node *copy, *copyTail; // Pointers to track the copied list and its tail
        copyTail = dummy; // Initialize the copy tail to the dummy node

        while (curr) {
            next = curr->next->next; // Save the next node in the original list

            copy = curr->next; // Extract the copied node
            copyTail->next = copy; // Append the copied node to the result list
            copyTail = copy; // Update the copy tail

            curr->next = next; // Restore the original list
            curr = next; // Move to the next node in the original list
        }

        return dummy->next; // Return the head of the copied list
    }
};
