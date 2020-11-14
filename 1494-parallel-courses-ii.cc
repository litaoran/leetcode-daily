class Solution {
public:
    
int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
    // brilliant dp solution!!!
    vector<int> prerequisite(n, 0);
    for (auto d : dependencies) {
        prerequisite[d[1]-1] |= (1 << (d[0]-1));
    }
    
    // 0. A state contains information for n courses.
    // 1. From old state to new state.
    // 2. For loop starts from 0 works because the state path will be Monotonically increasing.
    vector<int> dp(1<<n, n);
    dp[0] = 0;
    for (int i=0;i<(1<<n);i++) {
        
        int can_study = 0;
        for (int j=0;j<n;j++) {
            if ((i& prerequisite[j]) == prerequisite[j] ) {
                can_study |= (1<<j);
            }
        }
        can_study =   (~i & can_study);
        for (int sub=can_study; sub>0 ; sub= (sub-1) & can_study) {
            if (__builtin_popcount(sub) >k) {
                continue;
            }    
            dp[i|sub] = min(dp[i|sub], dp[i]+1);
        }
    }
    
    return dp[(1<<n)-1];
    
}
