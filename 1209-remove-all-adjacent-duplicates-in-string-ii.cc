class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<char> s;
        stack<int> s_num;
        
        for (int i=0;i<str.size();i++) {
            char c = str[i];
            if (!s.empty() && s.top()==c) {
                if (s_num.top()+1==k) {
                    s_num.pop();
                    s.pop();
                } else {
                    int new_num = s_num.top();
                    s_num.pop();
                    s_num.push(new_num+1);
                }
            } else {
                s.push(c);
                s_num.push(1);
            }
        }
        
        string res;
        while (!s.empty()) {
            res = string(s_num.top(), s.top()) + res;
            s.pop();
            s_num.pop();
        }
        return res;
    }
};
