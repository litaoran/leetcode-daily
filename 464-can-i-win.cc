class Solution {
public:
    // Have to store three states instead of two.
    
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal==0) {return true;}
        int sum = (maxChoosableInteger+1) * maxChoosableInteger /2;
        if (sum<desiredTotal) return false;
        
        int mask = 0; // use bit mask to store states which will used as the key for dp memorization.
        vector<int> nums(maxChoosableInteger);
        vector<int> dp((1<<maxChoosableInteger), -1);
        for (int i=1;i<=maxChoosableInteger;i++) {
            nums[i-1]=i;
        }
        return helper(dp, 0, nums, desiredTotal);
    }
    
    bool helper(vector<int>& dp, int mask, const vector<int>& nums, int left) {
         int n = nums.size();
        if (left<=0) { // since the sum of nums is large than the desiredTotal, so the flow will eventually stop here.
            return false; // lose
        }
        if (dp[mask]!=-1) {
            return dp[mask];
        }
        
        bool is_win = false;
        for (int i=0;i<n;i++) {
            if ((mask & (1<<i))==0) {
                if (helper(dp, mask|(1<<i), nums, left-nums[i]) == false) {
                    is_win = true;
                    break;
                }

            }
        }
        dp[mask] = (int)is_win;
        return dp[mask];
    }
};
