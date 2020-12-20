class Solution {
public:
    string get(vector<int> v) {
        string s = "";
        for (auto e : v) {
            s.append(to_string(e));
            s.append(":");    
        }
        return s;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> raw;
        if (nums.empty()) {return raw;}
        
        unordered_set<string> dedup;
        
        for (int i=0;i<nums.size();i++) {
            int len = raw.size();
            for (int j=0;j<len;j++) {
                if (nums[i] >= raw[j].back()) {
                    vector<int> tmp = raw[j];
                    tmp.push_back(nums[i]);
                    string s = get(tmp);
                    if (dedup.count(s) == 0) {
                        raw.push_back(tmp);
                        dedup.insert(s);
                    }
                }
            }
            raw.push_back( vector<int>{nums[i]} );
        }
        
        auto it = raw.begin();
        while (it!= raw.end()) {
            if (it->size()<2) {
                it = raw.erase(it);
                continue;
            }
            it++;
        }

        return raw;
    }
    
    
//  //   Dedup in recusive might be easier. https://leetcode.com/problems/increasing-subsequences/discuss/97124/C%2B%2B-dfs-solution-using-unordered_set    
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> seq;
//         dfs(res, seq, nums, 0);
//         return res;
//     }
    
//     void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
//         if(seq.size() > 1) res.push_back(seq);
//         unordered_set<int> hash;
//         for(int i = pos; i < nums.size(); ++i) {
//             if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
//                 seq.push_back(nums[i]);
//                 dfs(res, seq, nums, i + 1);
//                 seq.pop_back();
//                 hash.insert(nums[i]);
//             }
//         }
//     }    
};
