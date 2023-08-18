class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin(),arr.end()); //using sort to store min difference element in simpler manner
        vector<vector<int>>a;//storing pair 
        int d=INT_MAX;//initialising min diff with max
        for(int i=0;i<arr.size()-1;i++)//traversing array and storing min difference found till last
        {
            int di=arr[i+1]-arr[i];

            d=min(d,di);

            
        }
        for(int i=0;i<arr.size()-1;i++)//storing pairs of elemetn whichgives same min diff found above
        {
            if((arr[i+1]-arr[i]==d))
            {
                a.push_back({arr[i],arr[i+1]});
            }
        }
        return a;
    }
};