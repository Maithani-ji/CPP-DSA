class Solution {// using presum - k and searching  in map , if that value exists then ,that value gave sum =k, that why store its freq in count 
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> m;//using map to store the presum we getting , and its frequency , ie how much it occurs
        m[0]=1;//stroing 0 presum as 1 freq, for corner case example [3,-3,1,1]
        int c=0;//storing count of sum with k
        int presum=0;//initialising presum
        for(int i=0;i<nums.size();i++)//traversing thorugh array

            {
                presum+=nums[i];//adding values to presum
                int remove=presum-k;// storing presum-k value , and searching it in map
                c+=m[remove];//if that remove is present , add its freq to count
                m[presum]++;//and map that presum with increment freq
            } 
            return c;       
    }
};