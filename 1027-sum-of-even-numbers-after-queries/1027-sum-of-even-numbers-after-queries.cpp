class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        

        int es=0; // we took sum of all even element previously
        vector<int>ans; // creating array for storing sum of even element after each operation during traversing.


        for(auto n: nums)//we took sum of all even element previously
        {  if(n%2==0)
            es+=n;
        }

        for(auto q:queries)// we traverse through queries
        {

        if(nums[q[1]]%2==0)// check original number if it is even - remove it from even sum
        {
            es-=nums[q[1]];
           

        }
         nums[q[1]]+=q[0];// and do the operation , ie add queries q [1] value to nums[q[0]]. 

        if(nums[q[1]]%2==0) // after operation if value changed is even , add it to the even sum 
        {
            es+=nums[q[1]];
        }

            ans.push_back(es);// for each iteration store total even sum in ans array.
        }
        return ans;
        
    }
};