class Solution {
public:
    // dp[i][j] refers to the number of assignments which can lead to a sum j with upto the i^{th} index.
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size()==1) {
            return nums[0]==abs(S)? 1:0;
        }
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(S)> Sum) return 0;
        
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2*Sum+1));
        
        dp[0][Sum+nums[0]]++;
        dp[0][Sum-nums[0]]++;
        
        for (int i=1;i<n;i++) {
            for (int sum=-Sum;sum<=Sum;sum++) {
                int j = sum + Sum;
                
                if (j-nums[i]>=0) { // from '+' to get to the current state
                    dp[i][j]+=dp[i-1][j-nums[i]];
                }
                
                if (j+nums[i]< 2*Sum+1) { // from '-' to get to the current state
                    dp[i][j]+=dp[i-1][j+nums[i]];
                }
            } 
        }
        return dp[n-1][Sum+S];
    }
};
