class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size());
        sort(nums.begin(), nums.end());
        
        dfs(nums, used, {}, res);
        
        return res;
    }
    
    void dfs(vector<int>& nums, vector<bool>& used, vector<int> cur, vector<vector<int>>& res) {
        
        if (cur.size()==nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i=0;i<nums.size();i++) {
            if (used[i]) continue;
            if (i>0 && nums[i]==nums[i-1] && !used[i-1]) {
                continue;
            }
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, used, cur, res);
            cur.resize(cur.size()-1);
            used[i] = false;
        }
    }
};
