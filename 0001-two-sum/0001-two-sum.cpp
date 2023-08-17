class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();  
      
      
      vector<pair<int,int>> x;
      for(int i=0;i<n;i++)
      {
        x.push_back(make_pair(nums[i],i));
      }
      sort(x.begin(),x.end());
      int s=0;
      int l=n-1;
      while(s<l)
      { 
        int sum= x[s].first+x[l].first;
        if(sum==target)
        {

      
          return {x[s].second,x[l].second};
        }
        else if(sum < target)
        {
          s++;
        }
        else
        {
          l--;
        }
      }
      return {};
    }
};