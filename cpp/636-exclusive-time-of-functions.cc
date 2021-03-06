#include <iostream>
#include <sstream>

class Solution {
public:
    
    void parseLog(string log, int& id, bool& is_start, int& pos) {
        stringstream s(log);
        string s1,s2,s3;
        getline(s, s1, ':');
        getline(s, s2, ':');
        getline(s, s3, ':');
        
        id = std::stoi(s1);
        
        is_start=true;
        if (s2=="end") is_start=false;
        
        pos = std::stoi(s3);
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> pos;  // Store both the timestamp for start/end of a task and the walltime length of each task(as a negative value)
        stack<int> ids;
        
        for (int i=0;i<logs.size();i++) {
            int id, cur;
            bool is_start;
            parseLog(logs[i], id, is_start, cur);
            
            if (is_start) {
                ids.push(id);
                pos.push(cur);
            } else {
                ids.pop();
                int pending = 0;
                while (pos.top()<0) {
                    pending += pos.top(); pos.pop();    
                }
                int s = pos.top(); pos.pop();
                int e = cur;
                res[id] += e-s+1+pending;
                pos.push(-1*(e-s+1));  // store the walltime length as a negative value
            }
            
        }
        return res;
    }
};
