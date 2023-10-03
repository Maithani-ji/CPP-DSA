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

    ListNode* merge(ListNode* slow,ListNode* fast)
    {
        if(!slow)
        {
            return fast;
        }
        else if(!fast)
        {
            return slow;
        }
        ListNode* head=new ListNode();
        ListNode* dumm=head;
        // if(slow->val<fast->val)
        // {
        //     dumm->next=slow;
        //     slow=slow->next;
        //     dumm=dumm->next;
        // }
        // else
        // {
        //     dumm->next=fast;
        //     fast=fast->next;
        //     dumm=dumm->next;
        // }
        while(slow && fast)
        {
                if(slow->val<fast->val)
        {
            dumm->next=slow;
            slow=slow->next;
            
        }
        else 
        {
            dumm->next=fast;
            fast=fast->next;
            
        }
        dumm=dumm->next;
        }

        while(slow)
        {
             dumm->next=slow;
            slow=slow->next;
             dumm=dumm->next;
        }
        while(fast)
        {
            dumm->next=fast;
            fast=fast->next;
             dumm=dumm->next;
            
        }
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
        {
            return head;
        }

        
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        slow=sortList(slow);
        fast=sortList(fast);
        
        return merge(slow,fast);
    }
};