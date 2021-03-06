class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        
        int i = 0;
        int unique_count = 0;
        vector<int> freq(128, 0);
        for (int j=0;j<s.size();j++) {
            char c = s[j];
            freq[c]++;
            if (freq[c]==1) {
                unique_count++;
            }
            
            while (unique_count>2) {
                freq[s[i]]--;
                if (freq[s[i]] ==0 ) {
                    unique_count--;
                }
                i++;
            }
            res = max(res, j-i+1);
        }
        
        return res;
    }
};
