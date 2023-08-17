class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

                                        // question says if alice gives 1 candy and recieves 1 candy from bob then , sum of candies
                                        // after swapping for both should be same;
                                        //return no of candies alice has given  and bob has given to get their sum same.
        unordered_map<int,int> mp; // we use map - because it finds element in contant time O(1)

        int s1=0;
        int s2=0;
        for(auto x: aliceSizes) s1+=x;//alices sum of candy
        for(auto x: bobSizes) s2+=x;// bobs sum of candy
                               
                                  // s1-x+y=s2-y+x => conditon for true
        int d=(s2-s1)/2;
      //                              bobs candy given => y=x+(s2-s1)/2   >>   d=(s2-s1)/2; 

        for(auto x: bobSizes) mp[x]++; // storing bobs elemnts in map to find the y in constant time

        for(auto x:aliceSizes) // using alices array,traverse no of candies she can give to get exact y for fairy cANDY to get sum 
//                                        same
        {
            if(mp.find(x+d)!=mp.end())// if x+d is found in map of bob then , conditon validates and return x,y=> x+d
            {
                return {x,x+d};//return x,y
            }
        }

        return {};
        
    }
};