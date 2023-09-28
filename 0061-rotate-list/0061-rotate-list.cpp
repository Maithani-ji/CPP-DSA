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
    ListNode* rotateRight(ListNode* head, int k) {

  if(!head || !head->next || k==0)
        {
            return head;
        }

        ListNode *temp=head;
        int l=0;
        while(temp)
        {
            if(temp->next==NULL)
            {
                temp->next=head;
                l++;
                break;
            } 

            l++;
            temp=temp->next;
        }
       

             k=k%l;
            k=l-k-1;
            temp=head;
           while(k--)
           {
                temp=temp->next;
           }
           head= temp->next;
            temp->next=NULL;
            return head;

        
    }
};