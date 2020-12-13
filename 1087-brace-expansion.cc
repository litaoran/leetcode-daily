class Solution {
public:
    // stack
    vector<string> expand(string S) {
        int n = S.size();
                
        vector<string> res;
        res.push_back("");
            
        int i = 0;
        while (i<n) {
            vector<string> new_res;
            if (S[i]=='{') {
                i++;
                while (S[i] != '}') {
                    if (islower(S[i])) {
                        for (auto s : res) {
                            new_res.push_back(s+S[i]);
                        }
                    }
                    i++;
                }
            } else if (islower(S[i])) {
                for (auto s : res) {
                    new_res.push_back(s+S[i]);
                }
            } else {
                assert(false);
            }
            i++;
            res = new_res;
            new_res.clear();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
