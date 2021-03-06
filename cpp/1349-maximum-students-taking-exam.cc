class Solution {
public:
    
    // Time complexity: m* 2^n * 2^n
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(); int n = seats[0].size();
        
        // store all valid states;
        vector<int> validity(m, 0);
        for (int i=0;i<m;i++) {
            int v = 0;
            for (int j=0;j<n;j++) {
                v = (v<<1) + static_cast<int>(seats[i][j]=='.');
            }
            validity[i] = v;
        }    
        
        vector<vector<int>> dp(m+1, vector<int>(1<<n, -1));
        
        // A virtal front row is always valid with no students.
        for (auto& e : dp[0]) {e = 0;}

        for (int i=1;i<=m;i++) {
            int v = validity[i-1];
            for (int j=0;j<(1<<n);j++) {
                // 1. check if j is valid
                // 2. check that there isn't any adjancent students in this row
                if (( (v & j) != j) ||  (j<<1 & j) ) {
                    continue;
                }

                if ((j & v) == j && !(j & (j >> 1))) {
                    for (int k=0;k<(1<<n);k++) {
                        if (dp[i-1][k]!=-1 && !(j<<1 & k)  && !(j>>1 & k)) {
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + __builtin_popcount(j) );
                        }
                    }
                }
            } 
        }

        return *max_element(dp[m].begin(), dp[m].end());
    }
};
