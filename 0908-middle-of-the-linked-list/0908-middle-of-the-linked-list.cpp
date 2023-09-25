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

        int l=0;
        ListNode *temp=head;
        while(temp)
        {
            l++;
            temp=temp->next;
        }
                // if(l%2==0)
                // {
                //     l=(l/2)+1;
                // }
                // else
                // {
                //     l=l/2;
                // }

        l=(l%2==0 )? (l/2) : l/2;
        while(l)
        {
            head=head->next;
            l--;
        }
        return head;

    }
};