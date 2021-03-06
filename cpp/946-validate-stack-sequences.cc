class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int idx = 0;
        for (int i=0;i<pushed.size();i++) {
            s.push(pushed[i]);
            
            while (!s.empty() && idx<popped.size() && popped[idx]==s.top()) {
                s.pop();
                idx++;
            }
        }
        return idx==popped.size() && s.empty();
    }
};
