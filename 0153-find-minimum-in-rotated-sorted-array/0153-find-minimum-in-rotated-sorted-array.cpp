class Solution {
public:
    int findMin(vector<int>& nums) {

        int low =0;
        int high=nums.size()-1;
        int m=INT_MAX;

        while(low<=high)
        {
            int mid=low +(high-low)/2;

            if(nums[mid]>=nums[low]) // if left mid subarray is sorted then , low is the min , and remove the left 
            //                        subarray and go to right subarray
            {
                m=min(nums[low],m);
                low=mid+1;// after finding min , move the low to low=mid+1; since we find the min from left sorted arr
            }
            else// if mid right subarray is sorted , then mid might be the min and ,remove that right subarray and go 

            //     to left subarrray
            {
                m=min(m,nums[mid]);
                high=mid-1;// after finding min go toh high=mid-1 ie left subarray

            }
        }
        return m;
        
    }
};