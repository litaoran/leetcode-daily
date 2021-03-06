class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        dfs(candidates, target, 0, {}, res);
        return res;
        
    }
    
    void dfs(vector<int>& candidates, int target, int idx, vector<int> cur, vector<vector<int>>& res) {
        if (target<0) {return ;}
        if (target==0) {
            res.push_back(cur);
            return ;
        }
        if (idx>=candidates.size()) { return;}        
        
        int end = idx;
        while (end!=candidates.size()-1 && candidates[end]==candidates[end+1]) {
            end++;
        }
        int len = end - idx+1;
        
        dfs(candidates, target, end+1, cur, res);
        for (int i=0;i<len;i++) {
            cur.push_back( candidates[idx]);
            dfs(candidates, target-(i+1)*candidates[idx], end+1, cur, res);
        }
    }
};
