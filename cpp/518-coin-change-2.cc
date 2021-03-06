class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1));
        
        // dp[i][j] : the number of combinations to make up amount j by using the first i types of coins
        dp[0][0]=1; // handle cornor case.
        for (int i=1;i<=coins.size();i++) {
            dp[i][0]=1;
            for (int j=1;j<=amount;j++) {
                dp[i][j] = dp[i-1][j] +  (j>=coins[i-1]? dp[i][j-coins[i-1]]:0);
            }
        }
        
        return dp[coins.size()][amount];

    }

};
