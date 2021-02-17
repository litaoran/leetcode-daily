class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> dp;
        return dfs(s, dp, words);
    }
    
    vector<string> dfs(string s, unordered_map<string, vector<string>>& dp, unordered_set<string>& set) {
        if (s.empty()) {
            vector<string> res;
            res.push_back("");
            return res;
        }
        if (dp.count(s)!=0) {
            return dp[s];
        }
        
        
        vector<string> words;
        
        for (int i=0;i<s.size();i++) {
            string substr = s.substr(0, i+1);
            if (set.count(substr)!=0) {
                auto returned_res = dfs(s.substr(i+1), dp, set);
                for (auto elem : returned_res) {
                    if (elem.empty()) {
                        words.push_back(substr);
                    } else {
                        words.push_back(substr + ' ' + elem);
                    }
                }

            }
        }
        dp[s] = words;
        
        return words;

    }

};
