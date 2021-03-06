class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        
        // monotonic queue.  descending queue
        deque<int> q;  q.push_back(nums[0]);
        deque<int> index;  index.push_back(0);
        for (int i=1;i<n;i++) {
            
            dp[i] = q.front() + nums[i];
            if (i-index.front() >= k) {
                q.pop_front();
                index.pop_front();
            }
            while (!q.empty() && dp[i] >= q.back()) {
                q.pop_back();
                index.pop_back();
            }
            q.push_back(dp[i]);
            index.push_back(i);
        }
        return dp[n-1];
   
    }    
    
    
//     int maxResult(vector<int>& nums, int k) {
//         unordered_map<int, int> dp;
        
//         return helper(nums, k, nums.size()-1, dp);
//     }
    
    
//     int helper(vector<int>& nums, int k, int idx,  unordered_map<int, int>& dp) {
//         if (idx==0) {
//             return nums[idx];
//         }
//         if (dp.count(idx) != 0) {
//             cout << "!!";
//             return dp[idx];
//         }
        
//         int res = INT_MIN;
//         for (int i=idx-1;i>=0 && i>=idx-k; i--) {
//             res = max(res, helper(nums,k, i, dp));
//         }
//         res += nums[idx];
        
//         dp[idx] = res;
//         return res;
//     }
};
