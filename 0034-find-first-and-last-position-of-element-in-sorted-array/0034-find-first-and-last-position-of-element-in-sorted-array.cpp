class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { //USING BINARY SEARCH 

       
        int i=0; int l=nums.size()-1; // for first occurence , wehn we find target we keep its indices and search the left subarray 
        //                               for first occurence 
        int f=-1; //save first occurence of elemnt else -1
        while(i<=l)// same binary search 
        {
            int mid = i+(l-i)/2;

            if(nums[mid]==target)// *EXCEPTION - if find the target , save its indices and go to right subarray for 1st occurence 
            {
                f=mid;
                l=mid-1;//going to left subarray
            }
            else if(nums[mid]>target)
            {
                l=mid-1;
            }
            else i=mid+1;
        }
                                // for 2nd occurence , wehn we find target we keep its indices and search the right subarray 
        //                               for last occurence 
        int e=-1;//store last occurence of elemnt else -1
            i=0; l=nums.size()-1;
         while(i<=l)
        {
            int mid = i+(l-i)/2;

            if(nums[mid]==target)// *EXCEPTION - if find the target , save its indices and go to left subarray for last occurence
            {
                e=mid;
                i=mid+1;
            }
            else if(nums[mid]>target)
            {   
                l=mid-1;
               
            }
            else   i=mid+1;
        }


        return {f,e};
        
    }
};