class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {

                if(nums.size()==0) return false;

            for(int i=0;i<nums.size() && n!=0 ;i++) //traversing loop till end or n is not planted
            {
                if(nums[i]==0) // if we found a empty , we check its before and after also empty or not
                {
                        int next= (i==nums.size()-1) ? 0 : nums[i+1] ; // if last element , it is 0,since it
                                                                       // pass 1 st ( if - statement) or i+1 element

                        int prev= (i==0) ? 0 : nums[i-1]; // same for first else i-1


                        if(next==0 && prev ==0) // if prev and next is 0 we plant 
                        {   
                            nums[i]=1; // we plant it by 1
                            n--; // no plant to plant 
                        }
                }
            }
                if (n) // if left n then false
                {
                    return false;
                }
                else return true;
        
    }
};