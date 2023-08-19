// //Bruteforce Approach - O(n^3) time and O(n) space

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         set<vector<int>> s;
//         vector<vector<int>> output;
//         for (int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 for(int k = j+1; k < nums.size(); k++){
//                     vector<int> temp;
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         s.insert(temp);
//                     }
//                 }
//             }
//         }
//         for(auto allTriplets : s)
//             output.push_back(allTriplets);
//         return output;
//     }
// };

class Solution { //OPTIMISED   ---- T- n^2logn +nlogn    S-n
public:
    vector<vector<int>> threeSum(vector<int>& nums) {// using 2sum concept for 3sum 
        
        vector<vector<int>> v; // for storing triplet's whose sum =0
        set<vector<int>> s; // used for storing triplet which are unique not repeating
        sort(nums.begin(),nums.end()); // sort the array for easier calculation using 2sum sorted technique
        int t=0; // target
        for(int i=0; i<nums.size();i++)// for fixing 1 triplet and use other two as 2sum to find their sum with fix one to = to t
        {  
            int j=i+1;//initialising 2 pointer, 1st with fixed elemtn +1
            int k=nums.size()-1; // 2nd with last element

            while(j<k) // 2sum sorted algorithm
            {   int sum=nums[i]+nums[j]+nums[k];
                if(t==sum)
                {
                    s.insert({nums[i],nums[j],nums[k]});//inseting unique array of triplet which are equal to sum using set
                    j++;
                    k--;

                }
                else if(sum>t)
                {
                    k--;
                }
                else j++;

            }
        }

        for(auto i :s)
        {   
            v.push_back(i);//storing triplet array for return

        }
        return v;
    }
};