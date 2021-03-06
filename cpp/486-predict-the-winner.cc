class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) {return true;}
        
        vector<int> presum(n+1);
        for (int i=1;i<=n;i++) {
            presum[i]+=presum[i-1]+nums[i-1];
        }
        
        auto getSum = [&](int s, int e){
            return presum[e+1] - presum[s];
        };
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int len=1;len<=n;len++) {
            for (int i=0;i+len-1<n;i++) {
                int j = i+len-1;
                if (len==1) {
                    dp[i][j] = getSum(i, j); 
                } else {
                    dp[i][j] = max(getSum(i,j)-dp[i+1][j], getSum(i,j)-dp[i][j-1]);    
                }
                
            }    
        }
        return dp[0][n-1]*2 >= presum[n] ;
        
    }
};
