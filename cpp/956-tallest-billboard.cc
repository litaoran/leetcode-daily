class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int m_sum = accumulate(begin(rods), end(rods), 0);
        vector<vector<int>> dp(21, vector<int>(m_sum+1, -2));
        return helper(dp, rods,0,0,0);
    }
    
    // whats memoized is not the actual height but mem[(i,delta)] = gap
    // The gap needed to reach to the maximum height with rods[i:] and the current difference. 
    int helper(vector<vector<int>>& dp, vector<int>& rods, int idx, int sum1, int sum2) {
        if (dp[idx][abs(sum1-sum2)] != -2) {
            if (dp[idx][abs(sum1-sum2)]==-1) {
                return -1;
            } else {
                return dp[idx][abs(sum1-sum2)] + max(sum1,sum2);
            }
        }
        if (idx==rods.size()) {
            if (sum1==sum2) {
                return sum1;
            } else {
                return -1;
            }
        }
        int res = -1;
        res = max(res, helper(dp, rods,idx+1,sum1+rods[idx], sum2));
        res = max(res, helper(dp, rods,idx+1,sum1, sum2+rods[idx]));
        res = max(res, helper(dp, rods,idx+1,sum1, sum2));
        if (res == -1) {
            dp[idx][abs(sum1-sum2)]=-1;
        } else {
            dp[idx][abs(sum1-sum2)] = res - max(sum1, sum2);
        }
        
        return res;
    }
};
