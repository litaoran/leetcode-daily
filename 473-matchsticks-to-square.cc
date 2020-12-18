class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size()<4) return false;
        
        sort(nums.begin(), nums.end(), greater<int>()); // fixed the TLE line
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%4 !=0) {return false;}
        int avg = sum/4;
        
        vector<int> sides(4);
        unordered_map<int, unordered_map<string, bool>> dp;
        
        return helper(nums,0,sides,avg, dp);   
    }
    
    string getKey(vector<int> sides) {
        sort(sides.begin(), sides.end());
        string key = "";
        for (auto side : sides) {
            key += to_string(side);
            key += "-";
        }
        return key;
    }
    
    bool helper(vector<int>& nums, int cur, vector<int> sides, int avg, unordered_map<int, unordered_map<string, bool>>& dp) {
        
        string key = getKey(sides);
        if (dp[cur].count(key)!=0) {
            return dp[cur][key];
        }
        
        if (cur==nums.size()) {
            for (auto side : sides) {
                if (side!=avg) return false;
            }
            return true;
        }
        
        
        int val = nums[cur];
        for (int i=0;i<4;i++) {
            if (val+sides[i] > avg) { continue;}
            
            // int j = i;  // pruning optimization.  Avoid calculate duplicates
            // while (--j >= 0) {
            //     if (sides[i] == sides[j]) 
            //         break;
            // }    
            
            sides[i]+=val;
            bool res = helper(nums, cur+1, sides, avg, dp);
            sides[i]-=val;
            if (res) {
                dp[cur][key] = true;
                return true;
            }
        }
        dp[cur][key] = false;
        return false;
    }
};
