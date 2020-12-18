class Solution {
public:
    // this is a 0/1 knapsack problem, for each number, we can pick it or not. Let us assume dp[i][j] means whether the specific sum j can be gotten from the first i numbers. If we can pick such a series of numbers from 0-i whose sum is j, dp[i][j] is true, otherwise it is false.
    bool canPartition(vector<int>& nums) {
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if (Sum%2!=0) return false;
        int n = nums.size();
        
        vector<vector<bool>> dp(n, vector<bool>(Sum+1, false));
        

        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for (int i=1;i<n;i++) {
            dp[i][0] = true;
            for (int j=1;j<=Sum;j++) {
                dp[i][j] = dp[i-1][j];
                if (j>=nums[i] && dp[i-1][j-nums[i]]) {
                    dp[i][j]= true;
                }   
            }
        }
        return dp[n-1][Sum/2];
    }
};
