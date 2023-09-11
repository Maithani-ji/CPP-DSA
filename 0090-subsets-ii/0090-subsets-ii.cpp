class Solution {
public:
        vector<vector<int>>ans;

        void generate(int i,vector<int>nums,vector<int>v)
        {
            if(i==nums.size())
            {   
                ans.push_back(v);
                return;
            }

            v.push_back(nums[i]);
            generate(i+1,nums,v);
            while( i+1 < nums.size() && nums[i]==nums[i+1])
            {
                i++;
            }
            v.pop_back();
            generate(i+1,nums,v);
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>v;
        sort(nums.begin(),nums.end());
        generate(0,nums,v);
        return ans;
        
    }
};