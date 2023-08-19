class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //using TWO POINTERS
        
        int i=0;//initialising i to check the number repeated more than 2 , other move normal with e
         for(auto e:nums)//traversing through array
         {
         if(i==0 || i==1 || e!=nums[i-2])// 1->first 2 ie i=1 and i=2 index is valid for storing 2 same or different 
             //  element,thus i moving with e & replacing e with nums[i] ie no replacement since i and e indices same
             //  2-> if finding element more than 2 times , i gets fixed to the repeating 
             //  3rd elmennt ie when e==nums[i] and e moves forward ,if found e!=nums[i]
             //  then replace e value with i th value & move i forward too % cycle cont.                              
             {
                 nums[i]=e;
                 i++;

             }
         }
         return i;//i will be at the length of new array
    }
};