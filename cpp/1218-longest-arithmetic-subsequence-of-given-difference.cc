class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
    
        vector<int> dp(arr.size(), 1);  // dp[i] means the maximum length of the subsequence ending at index i.
        
        unordered_map<int, int> map; // val to idx 
        
        int res = 0;
        for (int i=0;i<arr.size();i++) {
            int val = arr[i];
            
            if (map.count(val-difference)!=0) {
                dp[i]+= dp[map[val-difference]];
            }
            map[val] = i; // always override because the same value with a larger index has more potential to include a subsequence ending at the larger index.
            res = max(res, dp[i]);
        }
        
        
        return res;
        
    }
};
