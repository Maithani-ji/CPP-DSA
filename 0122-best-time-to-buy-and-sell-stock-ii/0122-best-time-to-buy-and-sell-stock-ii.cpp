class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size()==0)
         {                                  //  'WE CAN BUY MORE THAN 1 STOCK' & SELL IT AND BUY AT SAME TIME TOO
             return 0;
         }
                                        //THINK IT LIKE AN UP DOWN GRAPH OF STOCK AND SUBTRACT UP TO BOTTOM
        int prof=0;
        int n= prices.size();

        for(int i=1;i<n;i++) // we only check the min number & its just next increasing number and adding it in 
                            // max profit and then move forward with same logic
        {
            if(prices[i]>prices[i-1])//checking if previous element is small then subtract it to get profit
            {
                prof += prices[i]-prices[i-1]; //adding all the profit from min-max subtraction
            }
        }
        return prof;
    }
};