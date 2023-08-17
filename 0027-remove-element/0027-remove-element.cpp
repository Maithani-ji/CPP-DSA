class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0;   //using c for pointing if we find different value than target
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]==val) //if target is found we move forward for other element
        {
                continue;
        }
        else    //if other elemnet found we use c pointer to replace the other value vith the target value positions 
                //  as c act as a a marker  while k iterator moves forward and c moves froward when we found        
                // different value than target and increment c
        {
            nums[c]=nums[k];
            c++;
        }
        }

        return c;
    }
};