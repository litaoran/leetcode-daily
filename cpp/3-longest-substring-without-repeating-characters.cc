class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0;
        
        unordered_set<char> set;
        int res = 0;
        
        for (int j=0;j<s.size();j++) {
            char c = s[j];
            bool already_exist = false;
            if (set.count(c)) {
                already_exist = true;
            } else {
                set.insert(c);
            }
            
            while (already_exist) {
                char cur = s[i];
                i++;
                if (cur == c) {
                    already_exist = false;
                    break;   // No need to erase it
                }
                set.erase(cur);
            }
            
            res = max(res, j-i+1);
        }
        
        return res;
    }
};
