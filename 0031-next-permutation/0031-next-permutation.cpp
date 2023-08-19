class Solution {
public:
    void nextPermutation(vector<int>& nums) { // using optimised code of permutation intuition
                                                // think permutation as a mountain increasing from both the side ex 14532
                                                // next permutation is 13245
                                                // 1st step - from back find n[i]<n[i+1] ie at k -- if k <0 ,no mountain,just 4thstep
                                                // 2nd step - from back find n[i]>n[k] ie at l
                                                //3rd step - swap elemtent at k and l
                                                // 4th step reverse from k+1 till end .

        int k,l;//stroing k th positon and lth position 
        int n=nums.size()-1;

        for(k=n-1;k>=0;k--)//starting from back-1 because to find n[i]<n[i+1]
        {
            if(nums[k]<nums[k+1])
            {
                break;//if found then break loop
            }
            
        }
        if(k<0)//and if founded position is < 0 , ie like 54321 which is end permutation then just reverse it - 12345 
        {
            reverse(nums.begin(),nums.end());
        }
        else//else just find lth positon 
        {
            for(l=n;l>=k;l--)
            {
                if(nums[l]>nums[k])//finding lth using nums[l]>nums[k] from back
                {
                    break;//if found stop
                }
            }
            swap(nums[k],nums[l]);//swap both the value at k and l
            reverse(nums.begin()+k+1,nums.end()); //and reverse at k+1
        }
        
    }
};