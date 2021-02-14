class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        
        dfs(S, 0, res);
        
        
        return res;
    }
    
    void dfs(string cur, int idx, vector<string>& res) {
        if (idx==cur.size()) {
            res.push_back(cur);
            return;
        }
        
        while (idx<cur.size() && isalpha(cur[idx])==false) {
            idx++;
        }
        
        if (idx==cur.size()) {
            res.push_back(cur);
        } else {
            cur[idx] = toupper(cur[idx]);
            dfs(cur, idx+1, res) ;
            cur[idx] = tolower(cur[idx]);
            dfs(cur, idx+1, res) ;
        }
        
    }
    
};
