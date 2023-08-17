class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++) // starting from 2 nd index as we can step max 2 steps ahead, logic is how we move ahead- by taking 1 step or 2 
        {
            cost[i]+=min(cost[i-1],cost[i-2]);// it changes the count[i] value to how it got to that position at min cost by previously taking 1 or 2 steps  -- thats why i started from 2
        }
        return min(cost[n-1],cost[n-2]);//we can take 1 or 2 step that why return min of last or last-1 to get minimum cost climbed by stairs.
    }
};