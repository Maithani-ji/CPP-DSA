class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end()); //sort the array for more efficient finding 
        int s=nums[0]+nums[1]+nums[2];// initialise sum wiht first three sum for checking purpose
  
        for(int i=0;i<nums.size()-1;i++)//iterate over eliment by fixing 1 elemnt among three
    {           int k=i+1; //using TWO pointers , ist start from fix elemnt +1
                 int j=nums.size()-1; // other starts from end -1
            while(k<j) // while both are not equal
            {
                int cs=nums[k]+nums[j]+nums[i];// store the current sum while traversing 
                if(abs(cs-target)<abs(s-target))//check the absolute diff btw current sum and previous sum with target
                {
                    s=cs;//if current sum is less than previous sum diff , then it is curr sum is closest to target
                }
                else if (cs<target)// else if sum is < target , move closer to taget, by incresing sum , ie k++ since increasingly 
                //                    sorted
                {
                    k++;
                }
                else// if cs is > target , reduce the sum by reducing j-- --> since increasingly sorted
                {
                    j--;
                }

            }


    }
    return s;


        
    }
};