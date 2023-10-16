class Solution {
public:
    int hIndex(vector<int>& cit) {
        int s=0;
        int e=cit.size()-1;
        int n=cit.size();
        int mid;

        while(s<=e)
        {
            mid=s+(e-s)/2;

            if(cit[mid]==(n-mid))
            {
                return cit[mid];
            }
            else if(cit[mid]>(n-mid))
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return n-s;
    }
};