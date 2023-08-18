class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) { //               num=sum;
                                //a. It updates the value of num by shifting it one position to the left (multiplying by 2) and adding the current element of nums. This operation (num * 2 + nums[i]) calculates the decimal value represented by the binary digits encountered so far.
//b. It takes the modulus of num with 5 ((num * 2 + nums[i]) % 5). This operation checks if the decimal value represented by the binary digits encountered so far is divisible by 5.
            vector<bool> b;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum = (sum * 2 + nums[i]);// turning binary to decimal - from 0-n-1---[1,1,1] 0*2+1=1 -> 1*2+1=3 --> 3*2+1=7 ie
            //                           2*pevsum+num;
            sum=sum%5;
            if(sum==0) // if that element /ble by 5 ,return true
            {
                b.push_back(true);
            }
            else 
            {
                b.push_back(false);
            }
        }
       
        return b;
    }
};
// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//         vector<bool> result;
//         int counter = 0;
//         for (int num : nums) {
//             counter = ((counter << 1) + num) % 5;
//             result.push_back(counter == 0);
//         }
//         return result;
//     }
// };