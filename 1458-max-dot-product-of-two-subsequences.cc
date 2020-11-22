class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        
        dp[m-1][n-1] = nums1[m-1] * nums2[n-1];
        for (int i=m-2;i>=0;i--) {
            dp[i][n-1] = max(nums1[i] * nums2[n-1], dp[i+1][n-1]);
        }
        for (int j=n-2;j>=0;j--) {
            dp[m-1][j] = max(nums1[m-1] * nums2[j], dp[m-1][j+1]);
        }
        
        for (int i=m-2;i>=0;i--) {
            for (int j=n-2;j>=0;j--) {
                // For a new state dp[i][j], there are two cases to get the maximum:
                // if both nums1[i] and nums2[j] are used
                //     res = nums1[i]*nums2[j] + dp[i+1][j+1](if dp[i+1][j+1] > 0)
                // else 
                //     max(dp[i+1][j], dp[i][j+1])
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);    
                int val = nums1[i]*nums2[j];
                dp[i][j] = max(dp[i][j], val + (dp[i+1][j+1]>0 ? dp[i+1][j+1]:0) );
            }
        }


        return dp[0][0];
    }
};
