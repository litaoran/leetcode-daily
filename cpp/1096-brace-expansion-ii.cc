class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int idx = 0;
        auto raw_res = helper(expression, idx);
        
        vector<string> res;
        for (auto& s : raw_res) {
            res.push_back(s);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    unordered_set<string> helper(string str, int& i) {
        unordered_set<string> res;  //  all unique values between the parenthesises pair.
        unordered_set<string> S;    // all unique values between a adjacent comma. 
        
        while (i<str.size() && str[i]!='}') {
            if (str[i]==',') {
                res.insert(S.begin(), S.end());
                S.clear();
                i++;
                continue;
            }
            
            unordered_set<string> t;
            if (str[i]=='{') {
                i++;
                t = helper(str, i);
                i++;
            } else {  
                t.insert(string(1, str[i]));
                i++;
            }
            
            // Merge the current substrs with the existing candidates.
            if (S.empty()) {
                S = t;
            } else {
                unordered_set<string> S2;
                for (auto& s1 : S) {
                    for (auto& s2 : t) {
                        S2.insert(s1+s2);
                    } 
                }
                swap(S,S2);
            }
        }
        res.insert(S.begin(), S.end());
        
        return res;   
    }
};
