class Solution {
public:
     // Check discussion: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture
    // Top down dp;
//     int minScoreTriangulation1(vector<int>& A) {
//         int n = A.size();
//         vector<vector<int>> dp(50, vector<int>(50));
//         return dfs(dp, A, 0, n-1);
//     }
//     
//     int dfs(vector<vector<int>>& dp, vector<int>& A, int i, int j) {
//         if (j-i<=1) {return 0;}
//         if (dp[i][j] != 0) {
//             return dp[i][j];
//         }
//         int res = INT_MAX;
//         for (int k=i+1;k<j;k++) {
//             res = min(res, dfs(dp, A, i,k) + dfs(dp, A, k, j)+A[i]*A[j]*A[k]);
//         }
//         dp[i][j] = res;
//         return dp[i][j];
//     }
    
    // Botton up DP  dp[i][j] Polygon with vertex index between [i,j], what's the mimum cost.
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(50, vector<int>(50));
        for (int i=n-1;i>=0;i--) {
            for (int j=i+2;j<n;j++) {
                int res = INT_MAX;
                for (int k=i+1;k<j;k++) {
                    res = min(res, dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n-1];
    }
};
