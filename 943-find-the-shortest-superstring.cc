class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        
        auto dist = [](const string& a, const string&b) {
            int min_dist = min(a.size(), b.size());
            for (int overlap_len = 0; overlap_len <= min(a.size(), b.size()); overlap_len++) {
                if (a.substr(a.size()-overlap_len, overlap_len) == b.substr(0, overlap_len)) {
                    min_dist = b.size() - overlap_len;
                }
            }
            return min_dist;
        };

        // cost[i][j] means the icnreased total length of adding A[j] to the end of A[i];
        vector<vector<int>> cost(n, vector<int>(n));        
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cost[i][j] = dist(A[i], A[j]);
            }
        }
        
        // Initializtion dp;
        // dp[mask][i]: the minimum cost to visit nodes in mask(those bits are set to 1) and ends at node i. 
        // Memorization of the combination and the last node instead of the permutation.
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(1<<n, vector<int>(n, -1));
        for (int i=0;i<n;i++) {
            dp[(1<<i)][i] = A[i].size();
        }
    
        for (int mask= 1;mask<(1<<n);mask++) {
            for (int j=0;j<n;j++) {
                if ((1<<j) == mask) {continue;} // state which is already initialized.
                if (!(mask & (1<<j))) {continue;} //The current mask can't end with j.
                for (int prev=0; prev<n;prev++) {
                    if (prev!=j  && (mask & (1<<prev))) {
                        
                        if (dp[mask - (1<<j)][prev] + cost[prev][j] < dp[mask][j]) {
                            dp[mask][j] = dp[mask - (1<<j)][prev] + cost[prev][j];
                            parent[mask][j] = prev;
                        }
                    }
                }
            }
        }
            
        // Concatenate string a and string b to a new string.
        auto concatenate = [](string&a, string&b) {
            int max_overlap = min(a.size(), b.size());
            for (int overlap_len = 0; overlap_len <= min(a.size(), b.size()); overlap_len++) {
                if (a.substr(a.size()-overlap_len, overlap_len) == b.substr(0, overlap_len)) {
                    max_overlap = overlap_len;
                }
            }
            return a.substr(0, a.size()- max_overlap) + b;
        };
        
        // Construct the shortest superstring.
        auto it = min_element(dp.back().begin(), dp.back().end());
        int cur = it - dp.back().begin();
        string res = A[cur];
        int cnt = 1;
        int mask = (1<<n) -1;
        while (cnt<n) {
            int prev = parent[mask][cur];
            string parent_string =  A[prev];
            res = concatenate(parent_string, res);
            mask -= (1<<cur);
            cur = prev;
            cnt++;
        }
        return res;
    }
};
