class Solution {
public:
    // "First of all, dp[i][j] in here means, the maximum coins we get after we burst all the balloons between i and j in the original array."
    // Note dp[i][j] doesn't include the burst of i or j.
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        
        for (int len=3;len<=n+2;len++) {
            for (int i=0;i+len-1<n+2;i++) {
                int j = i+len-1;

                for (int k=i+1;k<j;k++) {
                    dp[i][j] = max(dp[i][j], nums[k]*nums[i]*nums[j]+dp[i][k]+dp[k][j]);
                }
                
            }
        }
        
        return dp[0][n+1];
    }
};

