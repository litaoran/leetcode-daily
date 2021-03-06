class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream str(path);
        string cur;
        while(getline(str,cur,'/')) {
            if (cur == ".") continue;
            else if (cur == "..") { if (!s.empty()) s.pop();}
            else if (cur == "") continue;
            else s.push(cur);
        }
        // construct string.
        if (s.empty()) return "/";
        string res = "";
        while (!s.empty()) {
            res  = "/"+s.top() + res;
            s.pop();
        }
        return res;
    }
};
