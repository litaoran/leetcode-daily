class Solution {
public:
//     int mctFromLeafValues(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//         vector<vector<int>> max(n, vector<int>(n));
        
//         for (int len=1;len<=n;len++) {
//             for (int i=0;i+len-1<n;i++) {
//                 int j = i+len-1;
//                 if (i==j) {
//                     max[i][j] = arr[i];
//                 } else {
//                     max[i][j] = std::max(max[i+1][j], max[i][j-1]);
//                 }
//             }
//         }
//         for (int len=1;len<=n;len++) {
//             for (int i=0;i+len-1<n;i++) {
//                 int j = i+len-1;
//                 if (len==1) {
//                     dp[i][j] = 0;
//                 } else if (len==2) {
//                     dp[i][j] = arr[i] * arr[j];
//                 } else {
//                     for (int k=i;k<j;k++) {
//                         dp[i][j] = std::min(dp[i][j], dp[i][k]+dp[k+1][j]+max[i][k]*max[k+1][j]);
//                     }                    
//                 }
//             }
//         }
//         return dp[0][n-1];
//     }
    
    int mctFromLeafValues(vector<int>& arr) {        
        int res = 0;
        while (arr.size()>1) { 
            int min_index = 0;
            int min_product=INT_MAX;
            for (int i=1;i<arr.size();i++) {
                if (arr[i] * arr[i-1] < min_product) {
                    min_index = (arr[i] < arr[i-1])? i: i-1;
                    min_product = arr[i] * arr[i-1];
                }
            } 
            res += min_product;
            arr.erase(arr.begin()+min_index);
        }
        return res;
    }    
    
};
