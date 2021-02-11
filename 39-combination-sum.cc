class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        dfs({}, 0, 0, candidates, target, res);
        return res;
    }
    
    void dfs(vector<int> cur, int sum, int idx, vector<int>& candidates, int target, vector<vector<int>>& res) {
        if (sum > target) {return;}
        if (sum == target) { 
            res.push_back(cur);
            return ;
        }
        
        for (int i=idx;i<candidates.size();i++) {
            cur.push_back(candidates[i]);
            
            dfs(cur, sum+candidates[i], i, candidates, target, res);
            
            cur.resize(cur.size()-1);
        }
    }
    
};
