class Solution {
public:
//    int subarraysDivByK(vector<int>& nums, int K) {//using prefix sum and checking % of it ,if same remainder comes that means
//    //                                              k is added in that value to get the same product , ex 4%5=4 ->4+5=9%5=4 , 
//     //                                                                      9+5=14&5=4 hence for other no's too if repeated.
//     int count = 0;
//     unordered_map<int, int> mp;//will store the count of summ values
//     int sum = 0;
//     mp[0]++; // Initialize with the sum 0 (important for cases where sum is already divisible by K) like 5,10,15 or even in -ve
    
//     for (auto x : nums) {
//         sum += x;// using prefix sum
//         int temp = (sum % K + K) % K; // Calculate the remainder to handle negative sums// will give the same result as sum%k
        
//         if (mp[temp] > 0) {//if that sum freq >0 , ie k is added to same no more than once , then that remainer will occur >0.
//             count += mp[temp]; // Increment count by the frequency of the same remainder
//         }
//         mp[temp]++; // Update the frequency of the current remainder
//     }
//     return count;
                                        //SAME AS ABOVE JUST USE ARRAY SPACE INSTEAD OF MAPP SPACE , FOR 0 TO K-1 VALUES
int subarraysDivByK(vector<int>& nums, int K) {
    int count = 0;
    vector<int> remainderCount(K, 0); // Array to store counts of remainders
    int sum = 0;
    remainderCount[0] = 1; // Initialize with the sum 0 (important for cases where sum is already divisible by K)
    
    for (auto x : nums) {
        sum += x;
        int temp = (sum % K + K) % K; // Calculate the remainder to handle negative sums
        count += remainderCount[temp]; // Increment count by the frequency of the same remainder
        remainderCount[temp]++; // Update the frequency of the current remainder
    }
    return count;
}



};