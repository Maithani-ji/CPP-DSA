class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
        {
            return 0;
        }
            // we store minimum and subtract with other to find the mx profit in a iterative manner
        int mins=prices[0]; //taking min = 1st element as starting
        int maxp=0; // taking max as 0 in starting
        

        int n= prices.size();
        for(int i=0;i<n;i++)
        {
            mins = min(mins,prices[i]); //as we iterate forward we check the element smaller than the 'mins'
            int prof= prices[i]-mins; // we calculate the profit as we move forward with help of 'mins' and the     
                                        // element on which we are standing 
            maxp= max(maxp,prof);    // after calculating the profit we check max of previous max and profit 
        }
        return maxp;// return maxp if no max is there it return 0 as it is previously assigned
            
            
    }
};