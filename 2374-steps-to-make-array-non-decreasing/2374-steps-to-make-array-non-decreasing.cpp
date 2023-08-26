class Solution {
public:
    int totalSteps(vector<int>& nums) {

        stack<pair<int,int>>st;
        
        int ans=-1;
       for(int i=nums.size()-1;i>=0;i--)
        {
            int count=0;
            while(!st.empty() and st.top().first<nums[i])
            {
               
                count=max(count+1,st.top().second);
                 st.pop();
            }
            ans=max(ans,count);
             st.push({nums[i],count});
        }
        
      
        return ans;

        
    }
};