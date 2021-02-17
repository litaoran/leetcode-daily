class Solution {
public:
    
    // We could also use memorization to store the state of used vector.
    int countArrangement(int n) {
        vector<bool> used(n+1);
        return dfs(1, n, used);
    }
    
    int dfs(int idx, int n, vector<bool>& used) {
        if (idx==n+1) {
            return 1;
        }
        
        int res = 0;
        for (int i=1;i<=n;i++) {
            if (used[i]) continue;
            if (i%idx==0 || idx%i==0) {
                used[i] = true;
                res += dfs(idx+1, n, used);
                used[i]=false;
            }
        }
        return res;
    }
    
};
