class Solution {
public:
    // store the same pattern, find the maximum index distance between the same patterns.
    unordered_set<char> vowels{'a','e','i','o','u'};
    int findTheLongestSubstring(string s) {
        
        unordered_map<int, int> map{{0, -1}};
        
        int res = 0;
        int mask = 0;
        for (int i=0;i<s.size();i++) {
            char c = s[i];
            if (vowels.count(c) !=0) {
                mask ^= 1 << string("aeiou").find(c);
            }
            if (map.count(mask)!=0) {
                res = max(res, i-map[mask]);
            } else {
                map[mask] = i;
            }
        }
        
        return res;
    }
};
