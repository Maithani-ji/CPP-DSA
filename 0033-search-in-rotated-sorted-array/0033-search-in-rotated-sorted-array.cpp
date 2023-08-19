class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int e=nums.size()-1;

        while(l<=e)//using binary search with some modification
        {
            int mid = l+(e-l)/2;

            if(nums[mid]==target)
            {
                return mid; // till here same as binary search
            }
            if(nums[l]<=nums[mid]) // this check if left part of mid is sorted or not
            {
                if(target >= nums[l] and target <=nums[mid])//if left is sorted , then check the target value lies where, beyond mid 
                //                                             or before mid 
                {
                    e=mid-1;//if before mid then last index become mid -1
                }
                else 
                {
                    l=mid+1;//if beyond mid , then sstartt becomes mid+1
                }
            }
            else if(target >= nums[mid] and target<=nums[e])//if right is sorted
            {
                l=mid+1;//if beyond mid , then sstartt becomes mid+1
            }
            else
            {
                e=mid-1;//if before mid then last index become mid -1
            }
        }
        return -1;
    }
};