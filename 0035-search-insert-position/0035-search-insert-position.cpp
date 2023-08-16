class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
         return 0;
        
        int s=0;
        int e= nums.size()-1;
       
        while(s<=e)
        {   
            int m= s+(e-s)/2;
            if(nums[m]==target)
            {
                return m;
            }
            else if(nums[m]<target)
            {
                s=m+1;
            }
            else
            {
                e=m-1;
            }


        }
        return s;//iftarget is not present in the array , then the starting position "ie start variable - 's'" will automatically tell
                //  you the position which the target elemnt will be in if added. 
        
    }
};