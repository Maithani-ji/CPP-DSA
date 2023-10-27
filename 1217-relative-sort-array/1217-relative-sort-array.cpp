class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int>mp;

        for(auto it:arr1)
        {
            mp[it]++;
        }   
        arr1.clear();

        for(auto it:arr2)
        {
            while(mp[it])
            {
                arr1.push_back(it);
                mp[it]--;
                
            }
        }

        for(auto it:mp)
        {
           
                while(it.second--)
                {
                    arr1.push_back(it.first);
                }
            
        }
        return arr1;
    }
};