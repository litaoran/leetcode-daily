class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k==num.size()) return "0";
        
        stack<char> s;
        for (int i=0;i<num.size();i++) {
            char c = num[i];
            while (k>0 && !s.empty() && c<s.top()) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        
        while (k>0) {
            s.pop();
            k--;
        }
        string res;
        while (!s.empty()) {
            res.insert(res.begin(), s.top());
            s.pop();            
        }
        // Cornor case: leading 0 need to be cleaned up.
        auto iter = res.begin();
        while (iter!=res.end()-1 && *iter=='0') {
            iter = res.erase(iter);
        }

        return res;
    }
};
