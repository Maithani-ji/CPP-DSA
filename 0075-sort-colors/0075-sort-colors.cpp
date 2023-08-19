class Solution {
public:
    void sortColors(vector<int>& nums) { // 3 pointer appoach - we just need 0 in front 1 in mid and 2's in last 
    //  so we just move 0 ie r and 2 ie b , in front and back , after all the swap 1 ie g will gets its place 
    //  automatically

        int r=0;// 0
        int g=0;//1
        int b=nums.size()-1;//2
        while(r<=b)//we  just need to use pointer r and b , to place r and b color , green will place itself by their 
        //            operation 
        {
        if(nums[r]==2)// if r is 2 ie blue , then swap its value r to b , and decrement b , ie put from last and 
        //                    decrement b to put more b value to it
            {
                swap(nums[r],nums[b]);
                
                b--; // decrement b ie blue , since b is found at r and now placed from last -- where we want 001122
            }
            else if(nums[r]==0)//if r is 0 ie red iteself , swap itself with g from start to get 001122
            {
                swap(nums[r],nums[g]);
                g++;//increment g and increment r , since r is placced from start and g move forward too after replaced
                r++;
            }
            else 
            r++;// else if g is found move, just move r forward
        }
        
    }
};