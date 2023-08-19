class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { //same optimal logic as 'sum 2' using 2 pointer approach
        if(numbers.size()<2)
        {
            return {};
        }
        vector<int> z;

        int a=0; //1st pointer
        int b=numbers.size()-1; //2nd pointer
        while(a<b) // 1st < 2nd
        {
            if(numbers[a] + numbers[b]== target) // check - if found return indices
            {
                z.push_back(a+1);
                z.push_back(b+1);
                return z;
                
            }
            else if(numbers[a] + numbers[b] > target) // if found greater - reduce 2nd
            {
                b--;
            }
            else // if smaller increment 1st
            {
                a++;
            }
        }
        return {};
    }
};