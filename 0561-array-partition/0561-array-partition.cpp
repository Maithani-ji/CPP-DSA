class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

            if (nums.size()==0 || nums.size()%2!=0)
            {
                return 0;
            }
                sort(nums.begin(),nums.end()); // sorting and checking every two elements pair for min number
            int sum=0;
            for(int i=0 ; i<nums.size();i+=2)
            {
                sum+= min(nums[i],nums[i+1]); //getting sum of min numbers
            }

            return sum;

        
    }
};