class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> left(nums.begin(), nums.end());
        vector<int> cur;
        dfs(cur, left, res);
        
        return res;
    }
    
    void dfs(vector<int> cur, unordered_set<int>& left, vector<vector<int>>& res) {
        if (left.empty()) {
            res.push_back(cur);
            return;
        }
        
        unordered_set<int> tmp(left);
        for (auto elem : left) {
            cur.push_back(elem);
            tmp.erase(elem);
            dfs(cur, tmp, res);
            tmp.insert(elem);
            cur.resize(cur.size()-1);
        }
    }
    
};
