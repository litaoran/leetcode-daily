#include <iostream>
#include <unordered_map>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    
    // backtracking + memorization
    int minStickers(vector<string>& stickers, string target) {
        unordered_map<string, int> dp;
        int n = stickers.size();
        vector<vector<int>> countMap(n, vector<int>(26,0));
        for (int i =0 ;i<stickers.size();i++) {
            string s = stickers[i];
            for (auto c : s) {
                countMap[i][c-'a']++;
            }
        }
        
        helper(dp, countMap, target);        
        return dp.count(target)==0 ? -1 : dp[target];
    }
    int helper(unordered_map<string, int>& dp, vector<vector<int>>& countMap, string target) {
        if (dp.count(target) !=0) {return dp[target];}
        if (target.size()==0) {return 0;}
        
        
        vector<int> tmp(26, 0);
        for (char c : target) tmp[c-'a']++;
        
        int res = INT_MAX;
        for (int i=0;i<countMap.size();i++) {
            string left = "";
            for (int j=0;j<26;j++) {
                if (tmp[j] - countMap[i][j] > 0) {
                    left += string(tmp[j] - countMap[i][j], 'a'+j);
                } 
            }
            // Optimization. Skip backtracking if the current sticker doesn't spell out any left characters.
            if (left==target) continue;
            int num = helper(dp, countMap, left);
            if (num != -1) {
                res = min(res, num+1);
            }
        }
        res = res==INT_MAX? -1: res;
        dp[target] = res;
        return res;
    }
};
