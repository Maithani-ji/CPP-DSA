class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        int greater=nums[0];//will store the max value while traversing
        int leftmax=nums[0];//will store the value greater when we found a partition , ie num<leftmax, ie we have to add it in partition and , that num index is the partition

        int ans=0;

        for(int i=1;i<nums.size();i++)//we traverse the array
        {
            if(nums[i]<leftmax)//if found number less than leftmax ie number should be included in partition ,
            //                      then that number indx will be assigned to ans , and greater value to new leftmax
            {
                leftmax=greater;
                ans=i;
            }
            if(nums[i]>greater)//if found no >greater than assign that value to greater
            {
                greater=nums[i];
            }
        }
        return ans+1;
    }
};

// class Solution {                         //using extra space ie S-n using to store right minimum using CHAINING method, 
//                                            for left max and right min
// public:
//     int partitionDisjoint(vector<int>& nums) {

//         int n=nums.size();
//         vector<int>rmn(n+1);
       
//         rmn[n]=INT_MAX;
//         for(int i=n-1;i>=0;i--)
//         {
//             rmn[i]=min(nums[i],rmn[i+1]);
//         }

//         int lmx=INT_MIN;
//         int ans=0;
//         for(int i=0;i<n-1;i++)
//         {
//             lmx=max(nums[i],lmx);
//             if(lmx<=rmn[i+1])
//             {
//                 ans=i;
//                 break;
//             }
//         }

//         return ans+1;
//     }
// };