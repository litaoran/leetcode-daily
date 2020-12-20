class Solution {
public:
    void construct(vector<vector<string>>& equations, vector<double>& values, unordered_map<string, unordered_map<string, double>>& g) {
        for (int i=0;i<equations.size();i++) {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            
            g[s1][s2] = values[i];
            g[s2][s1] = 1.0/values[i];
        }
    }

    double get(unordered_map<string, unordered_map<string, double>>& g, string b, string e) {
        if (g.count(b)==0 || g.count(e)==0) {
            return -1.0;
        }
        
        queue<string> q;
        queue<double> vals;
        unordered_set<string> visited;
        q.push(b);
        vals.push(1.0);
        visited.insert(b);
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                string cur = q.front();  q.pop();
                double val = vals.front(); vals.pop();
                if (cur==e) {
                    return val;
                }    
                    
                for (auto [next, v] : g[cur]) {
                    if (visited.count(next) !=0) {
                        continue;
                    }
                    visited.insert(next);
                    q.push(next);
                    vals.push(val * v);
                }
            }
        }
        return -1.0;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        construct(equations, values, g);
            
        vector<double> res;
        for (auto q : queries) {
            string b = q[0];
            string e = q[1];

            res.push_back(get(g, q[0], q[1]));
        }
        
        return res;
    }
};
