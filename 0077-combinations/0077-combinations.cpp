class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void generate(int n,int k,int i)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        if(i>n || v.size()>k)
        {
            return;
        }

        v.push_back(i);
        generate(n,k,i+1);
        v.pop_back();
        generate(n,k,i+1);


    }
    vector<vector<int>> combine(int n, int k) {

        generate(n,k,1);
        return ans;


        
    }
};