class Solution {
public:    
    // bottom up dp.
    int minCost(int n, vector<int>& cuts) {
        if (cuts.size()==0) {return 0;}
        if (cuts.size()==1) {return n;}

        vector<int> c(cuts);
        c.push_back(0);
        c.push_back(n);
        sort(c.begin(), c.end());
        
        int m = c.size();
        vector<vector<int>> dp(m, vector<int>(m));
        
        for (int len=3;len<=m;len++) {
            for (int i=0;i+len-1<m;i++) {
                int j = i+len-1;
                
                int tmp = INT_MAX;
                for (int k=i+1;k<j;k++) {
                    tmp = min(tmp, dp[i][k]+ dp[k][j]);   
                }
                dp[i][j] += (tmp==INT_MAX ? 0:tmp) ;
                dp[i][j] += c[j]- c[i];
            }
        }
        
        return dp[0][m-1];
    }
};
