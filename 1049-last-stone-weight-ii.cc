class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
     
        // This question equals to partition an array into 2 subsets whose difference is minimal    
        // why?  
        //   Not matter what order you eventually find to smash the rocks, you could always convert it to the difference between two groups.   e.g. ((b-(c-a))-d)  =>   (b+a) - (c+d)
        // Then it's a classical knapsack problem
        
        int Sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        // dp[i][j]:  With the first i-th stones, could we select a subset with the sum equals to j. 
        vector<vector<bool>> dp(n, vector<bool>(Sum+1, false));
        
        dp[0][0] = true;
        dp[0][stones[0]] = true;
        for (int i=1;i<n;i++) {
            dp[i][0] = true; // a subset could always achieve the zero sum by not picking any stones.
            for (int sum=1;sum<=Sum;sum++) {
                dp[i][sum] = dp[i-1][sum];
                if (sum - stones[i]>=0 && dp[i-1][sum-stones[i]]) {
                    dp[i][sum] = true;
                }
            }
        }
        
        
        int res = INT_MAX;
        for (int sum=1;sum<=Sum;sum++) {
            if (dp[n-1][sum]) {
                res = min(res, abs(Sum-2*sum));
            }
        }
        
        return res;
    }
};
