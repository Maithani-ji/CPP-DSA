class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
       { return 0;}

        int maxs=nums[0]; // or INT_MIN 
        int curs=0;

        for(auto i : nums)
        {
            if(curs<0)
            {
                curs=0;
            }
            curs=curs+i; // curs gives current sum ie stroing sum of subarrays part by part..
            maxs= max(maxs,curs); // maxs storing the maximum sum gain by the summing of subbaray by comparing with 
                                    //the previous sum and currents sum
            
        }
        return maxs;

    }
};