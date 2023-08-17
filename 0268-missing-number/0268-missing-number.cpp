class Solution {
public:
    int missingNumber(vector<int>& nums) {
      // USING CARL GAUSS n(n+1)/2 which gives sum of range 0 to n  

        int n= nums.size();
        int sum= n*(n+1)/2; // getting sum of range
        int s=0;
        for(auto i : nums)
        {
             s+=i; // getting sum of values present in the range

        }
        if(s==sum) // if same then all values are present
        {
            return 0;
        }
        else
        {
            return sum-s; // if not present then the value which is left after subtraction is missing 'value'
        }

    }
};