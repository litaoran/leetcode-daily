class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        vector<int> freq(128);
        int res = 0;
        int total = 0;
        int i=0;
        for (int j=0;j<s.size();j++) {
            freq[s[j]]++;
            if (freq[s[j]]==1) {total++;}
            
            
            while (total>k) {
                freq[s[i]]--;
                if (freq[s[i]]==0) {
                    total--;
                }
                i++;
            }
            
            res = max(res, j-i+1);
            
        }
        
        return res;
    }
};
