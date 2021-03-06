class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
    
        return helper(nums, target, dp);
    }
    
    // Time complexity: maybe O(target* N)
    int helper(vector<int>& nums, int target, unordered_map<int, int>& dp) {
        
        if (target==0) {return 1;}
        if (target<0) {return 0;}
        if (dp.count(target)!=0) {return dp[target];}
        
        
        int sum = 0;
        for (int i=0;i<nums.size();i++) {
            sum += helper(nums, target-nums[i], dp);
        }
        dp[target] = sum;
        
        
        return sum;
    }
    
};
