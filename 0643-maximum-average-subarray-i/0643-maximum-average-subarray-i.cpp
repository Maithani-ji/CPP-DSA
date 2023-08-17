class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(k>nums.size()) // using two pointers SLIDING WINDOW
        {
            return 0;
        }

        double sum=0; //taking sum
        for(int i=0;i<k;i++)
        {
            sum+=(double)nums[i]; //sum of first k 

        }
        double mx=sum; //initialising max with sum
        int n= nums.size();
        for(int i=0;i<n-k;i++)  // traversing n-k left elements
        {
            sum=(sum-(double)nums[i]+(double)nums[i+k]); // to get next k subarray sum , remove 1st element and add 
                                     //last +1 elemnt till 
                                        // last element
            
            mx=max(mx,sum);//storing max of either recent or previous sum 

        }

        return mx/k; // giving avg of the max sum 
        
    }
};