class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int l, int r) {//using two pointer sliding window
        int i=0; int j=0; int count =0; int m=0;// l and r is range ie [l,r]-> max value must be in that range 

        while(j<a.size())
        {
            if(a[j]>r)// value exceeds range ie >right
            {
                m=0;// then m ie no of subarray for that no is 0 and not be included in any subarray or start a subarray
                i=j+1;// and new subarray starts from j+1
            }
            else if(a[j]>=l and a[j]<=r)//if value in ranje , then no of subarray having that max is j-i+1
            {
                m=j-i+1;
            }// else if value exceed below range <l then it wont be maximum and not the starting of any subarray but can be included in subarray , thus previous value of m is added
            
            count +=m;// count will be number of subarrray for that value
            
            j++;// move j forward
         }
        return count;
    }
};