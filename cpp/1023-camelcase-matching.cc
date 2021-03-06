class Solution {
public:
    bool match(string query, string pattern) {
        int i = 0; int j =0;
        
        while (i<query.size() && j<pattern.size()) {
            if (query[i]==pattern[j]) {
                i++;j++;
            } else if( isupper(query[i])) {
                return false;
            } else {
                i++;
            }            
        }
        
        // if any pattern left, return false.
        if (j!=pattern.size()) {return false; }
        
        // if pattern is complete and query only has lowercase characters left, return true
        for (i;i<query.size();i++) {
            if (isupper(query[i])) {
                return false;
            }
        }
        return true;

    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        
        for (auto q : queries) {
            res.push_back( match(q, pattern));
        }
        
        return res;
    }
};
