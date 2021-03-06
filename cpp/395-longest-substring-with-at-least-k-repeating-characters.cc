class Solution {
public:
    // Divide and conquer
    int longestSubstring(string s, int k) {
        if (s.size()==0) return 0;
        
        vector<int> freq(26);
        for (auto c : s) {
            freq[c-'a']++;
        }
        
        int i=0;
        int res = 0;
        while (i<s.size() && freq[s[i]-'a']>=k) {
            i++;
        }
        
        if (i==s.size()) {
            return s.size();
        } 
        
        int left =  longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i+1), k); // using the size n as the start position in substr function is fine.
        return max(left, right);
    }
    
//     // Brute force: TLE
//     int longestSubstring(string s, int k) {
//         int res = 0;
//         for (int i=0;i<s.size();i++) {
//             unordered_set<char> set;
//             int group = 0;
//             vector<int> freq(26);
//             for (int j=i;j<s.size();j++) {
//                 set.insert(s[j]);
//                 freq[s[j]-'a']++;
//                 if (freq[s[j]-'a']==k) {group++;}
//                 if (set.size() == group) {
//                     res = max(res, j-i+1);
//                 }
//             }
//         }
        
//         return res;
//     }
};
