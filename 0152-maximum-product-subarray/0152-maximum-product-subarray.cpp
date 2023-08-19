class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0];//using max for storing max product value for non -ve
        int mn=nums[0];// if -ve included we use min too
        int ans=nums[0];//we will store max product value in ans
        for(int i=1 ; i<nums.size();i++)// traverse fron 1st because we already have 0th value stores in mn mx
        {
            if(nums[i] <0)//if value is -ve 
            {
                swap(mx,mn);//swap mn and mx ,since if -ve * with mx it will give bigger -ve product 
                //            hence -ve * with mn will give smaller -ve product 
                // if -ve occcur 2 or in multiple of 2 ,then max will get its bigger product with +ve sign back since -*-=+
            }
            mx= max(nums[i],nums[i]*mx);//mx store either new subbarray value when encounter -ve or that value * with 
            //                               previous element in continuing subarray
            mn= min(nums[i],nums[i]*mn);// mn store min value, to be swapped with mx , when -ve comes, because -ve mx will
            //                           give more minimum value
            ans=max(ans,mx);//ans will store max of mx and ans
        }
return ans;        
    }
};