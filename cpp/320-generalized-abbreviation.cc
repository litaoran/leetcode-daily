class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(0, word, res);
        return res;
    }
    
    void dfs(int idx, string cur, vector<string>& res) {
        if (idx==cur.size()) {
            string word="";
            int i = 0;
            while (i<cur.size()) {
                if (isalpha(cur[i])) {
                    word += cur[i];
                    i++;
                } else {
                    int cnt = 0;
                    while (i<cur.size() && isdigit(cur[i])) {
                        i++;
                        cnt++;
                    }
                    word += to_string(cnt);
                }
            }
            res.push_back(word);
            return ;
        }
        
        
        dfs(idx+1, cur, res);
        cur[idx]='1';
        dfs(idx+1, cur, res);
    }
};
