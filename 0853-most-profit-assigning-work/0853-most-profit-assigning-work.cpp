class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        
        // Create a vector of pairs to represent each job with its difficulty and profit
        vector<pair<int, int>> job(diff.size());

        // Populate the job vector with difficulty and profit from the input vectors
        for(int i = 0; i < profit.size(); i++) {
            job[i] = {diff[i], profit[i]};
        }

        // Sort the worker abilities in ascending order
        sort(worker.begin(), worker.end());

        // Sort the job vector by difficulty in ascending order
        sort(job.begin(), job.end());

        int mx = 0;     // Variable to store the maximum profit
        int i = 0;      // Index to iterate through the sorted job vector
        int curmax = 0; // Variable to store the maximum profit for the current worker

        // Iterate through each worker's ability
        for(auto w : worker) {
            // Initialize the maximum profit for the current worker

            // Find jobs that the current worker can complete and maximize profit
            while(i < job.size() && job[i].first <= w) {
                curmax = max(curmax, job[i].second);
                i++;
            }

            mx += curmax; // Accumulate the maximum profit for all workers

        }

        return mx; // Return the overall maximum profit achievable
    }
};
