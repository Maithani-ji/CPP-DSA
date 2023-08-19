class Solution {
public:
    bool search(vector<int>& nums, int k) {
        
        int low=0;
        int high=nums.size()-1;

        while(low<=high)
        {
            int mid= low+(high-low)/2;

            if(nums[mid]==k) return true;//check if found target , return true
            if(nums[mid]==nums[low] && nums[mid]==nums[high])// if low ,mid and high have same element , trim low and 
            //                                                  high and continue till found different one.
            {
                low++;
                high--;
                continue;
            }

            if(nums[mid]>=nums[low])//if mid left sub array is sorted ,traverse there 
            {
                if(nums[mid]>=k && nums[low]<=k)//if target is between the left subarray then high = mid-1
                {
                    high=mid-1;
                }
                else low = mid+1;//else outside of left subarray - low=mid+1;

            }
            else//if mid right sub array is sorted traverse there 
            {
                if(nums[mid]<=k && nums[high]>=k)//if target is between right subarry , then low = mid+1
                {
                    low=mid+1;
                }
                else high =mid-1;// else outside right subarray , move high =mid-1
            }
        }
        return false;
    }
};