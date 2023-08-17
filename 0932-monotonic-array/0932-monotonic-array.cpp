class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        if(nums.size()==0)
        {
            return false;
        }

bool c=true;//increasing 
bool c1 =true;//decreasing 
        for(int i=0;i<nums.size()-1;i++)
        {
           
            if(nums[i]<nums[i+1])// increasing then decreasing false
            {
                c1=false;
            }
            if(nums[i]>nums[i+1])//decreasing then increasing false
            {
                c=false;
            }
        }
        return c1 || c;
        
    }
};