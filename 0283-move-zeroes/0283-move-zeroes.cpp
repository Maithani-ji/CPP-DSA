class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0)
        { return ;
        }
                                          //using 2 pointer approach
        int k=0;       //pointer 2 
        for(int i=0;i<nums.size();i++)// traversing array
        {
            if(nums[i]==0)//checking value if zero , then move forward in array
            {
                continue;
            }
            else{             // if not , then movie non zero to kth position
                nums[k]=nums[i];
                k++;          // and incremeent k to next +1 for next position
            }

            
                                // done for non zero value till k -1 
                                //after k-1....

        }
        while(k<nums.size())   // for zero values-- use k to n-1 to fill all with zero 
            {
                nums[k]=0;
                k++;
            }
    }
};