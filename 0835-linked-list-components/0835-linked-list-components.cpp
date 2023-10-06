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
    int numComponents(ListNode* head, vector<int>& nums) {

        set<int>s;
        for(auto i: nums){
            s.insert(i);
        }

        bool flag=false;
        int count=0;

        while(head)
        {
            if(s.count(head->val) and !flag)
            {
                flag=true;
                count++;
            }
            else if(!s.count(head->val)) 
            {
                flag=false;
            }

            head=head->next;

        }
        return count;
    }
};