class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int low=0; // initialising low and high -->low shows start of subarr and high show end of subarr
        int high = nums.size()-1;

        while(low+1 < nums.size() && nums[low] <= nums[low+1]) //check from where elements are not sorted and store its
                                                                        // index
        {
            low++;
        }

        while(high-1 >= 0 && nums[high-1] <= nums[high])// check till when it is not sorted and store its index
        {
            high --;
        }
        if(low ==nums.size()-1) // if starting is end everything is sorted
        {
            return 0;
        }

        int m=INT_MAX;
        int ma=INT_MIN;

        for(int i=low;i<=high;i++)//storing min and max of subbarray
        {
            m=min(m,nums[i]);
            ma=max(ma,nums[i]);

        }

        while(low-1 >=0 && nums[low-1]>m )// check elements prior of starting  for min ,  if exist greater than min of subbaray change starting  [4,3,5,1,9,7,6] - start 5 end  7
        {
            low--;
        }
        while(high +1 <=nums.size()-1 && nums[high+1] < ma )//check element after end of sUBARR , if found smaller than max change end
        {
            high++;
        }
        return (high-low+1); //return end - start+1
    }
}; 