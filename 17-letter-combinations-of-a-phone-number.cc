class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> map({{2, {'a', 'b','c'}}, {3, {'d', 'e','f'}}, {4, {'g', 'h','i'}}, {5, {'j', 'k','l'}},{6, {'m', 'n','o'}}, {7, {'p', 'q','r','s'}}, {8, {'t', 'u','v'}}, {9, {'w', 'x','y', 'z'}}});
        
        
        vector<string> res;
        if (digits.empty()) {return res;}
        
        dfs("", digits, 0, map, res);
        return res;
        
    }
    
    void dfs(string cur, string digits, int idx, unordered_map<int, vector<char>>& map, vector<string>& res) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return ;
        }
        
        char digit = digits[idx];
        for (auto letter : map[digit-'0']) {
            string next_str =  cur + letter ;
            dfs(next_str, digits, idx+1, map, res);        
        }
    }
    
};
