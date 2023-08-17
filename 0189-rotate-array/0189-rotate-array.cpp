class Solution {
public:
    void rotate(vector<int>& nums, int k) {

       
       k=k% nums.size(); // using modulus because if rotation given more than array size ,then after size k rotation 
                            // it will become original array so, we dont need to rtate more than array size just get
                            //remainder of rotation and size.
       reverse(nums.begin(),nums.end());  // first reversing whole array
       reverse(nums.begin(),nums.begin()+k); // reversing first k part 
        reverse(nums.begin()+k,nums.end()); // reversing last k part

        // end is n not n-1  end=n ie length , it works till n-1.
       

        

    }
};