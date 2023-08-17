class Solution {
public:  // CAN also use sorting and then max of  product of 1st two and last & product of last 3  T-NLOGN S-1 
    int maximumProduct(vector<int>& nums) { // using 3 variables for max and 2 min variables   T-N S-1
       
                             // using 2 MIN variable because 2 min ie 2-ve and last max prod also give max 
                                            //prod
    
        
        int m1=INT_MIN; //CREATING 3 VARIABLE FOR MAX
        int m2=INT_MIN;
        int m3=INT_MIN;

        int m4=INT_MAX;//creating 2 min variable 
        int m5 =INT_MAX;
        
        
        for(int i=0;i<nums.size();i++)//traversing
        {       
            //checking max variables and assigning 3 max elements
            if(nums[i]>m3)
            {   
                m1=m2;
                m2=m3;
                m3=nums[i];

            }
            else if(nums[i]>m2)
            {
                m1=m2;
                m2=nums[i];
            }
            else if(nums[i]>m1) {
            m1=nums[i];
            }

                // checking and assigning 2 min element
            if(nums[i]<m4){
                m5=m4;
                m4=nums[i];

            }
            else if(nums[i]< m5 )
            {
                m5=nums[i];
            }
            
        }
        int c=m4*m5*m3;
        int d=m1*m2*m3;
         return  max(c,d); //if -ve present then 2 min ie 2 -ve prod can give +ve max number with 
                                             //3rd max
                                             // or 3 max number product can give max product
       
    }
};