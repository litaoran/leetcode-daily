class Solution {
public:
    
    bool isValid(vector<int> freq) {
        for (auto elem : freq) {
            if (elem <=0) return false;
        }
        return true;
    }
    
    int numberOfSubstrings(string s) {
        int res = 0;
        int i = 0; int j = 0;
        
        vector<int> freq(3,0);
        
        while (j<s.size()) {
            freq[s[j]-'a']++;
            j++;
            
            while (i<j && isValid(freq)) {      
                freq[s[i]-'a']--;
                i++;
            }
            res+= i;  // all substrings that end at j and start before i should be valid results
        }
        return res;
    }
};
