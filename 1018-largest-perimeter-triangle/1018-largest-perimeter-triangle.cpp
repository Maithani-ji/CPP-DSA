class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

                                            //triangle is possible if l1<l2<l3 and l1+l2>l3
        sort(nums.begin(),nums.end()); // we sort the array incresing order

        for(int i=nums.size()-1;i>1;i--)//traverse from back
        {
            int l1=nums[i];//store n
            int l2 =nums[i-1];//store n-1
            int l3=nums[i-2];//store n-2

            if(l3+l2>l1)//if last element is < than sum of previous two , then it give the max perimeter else traverse back more
           { return l1+l2+l3;}

        }
        return 0; // if not found any return 0
    }
};