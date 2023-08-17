class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        if(nums.size()==0)
        {
            return 0;
        }

        // we can use set // to get in time coplexity N and space used N
        // or we can use sorting and removing duplicate element and returning max 3 or max - T-nlogn S-1
        
        if(nums.size()==2)    // or use three variables -- T-n  S-1
        {
            return max(nums[0],nums[1]);
        }

        long m1= LONG_MIN; //storing 1st max
        long m2=LONG_MIN; // storing 2nd max
        long m3=LONG_MIN; // storing 3rd max

        for(auto i:nums)
        {       
              if(i==m1|| i==m2|| i==m3)
            {
                continue;
            }

            if(i>m1)
            {
                m3=m2;
                m2=m1;
                m1=i;
            }
            else if(i>m2)
            {
                m3=m2;
                m2=i;
            }
            else if(i>m3)
            {
                m3=i;
            }

          
        }

                if(m3==LONG_MIN)
                {
                    return m1;
                }

               else{ return  m3;}

    }
};


