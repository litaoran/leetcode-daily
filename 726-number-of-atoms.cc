class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int> s;
        int n = formula.size();
        vector<int> closed(n, -1);
        for (int i=0;i<formula.size();i++) {
            if (formula[i] =='(') {
                s.push(i);    
            } else if (formula[i] ==')') {
                int open = s.top(); s.pop();
                closed[open] = i; 
            }
        }
        
        auto raw_res = helper(closed, formula, 0, n-1);

        string res;
        for (auto [name, count] : raw_res) {
            res = res + name;
            if (count>1) {
                res = res + to_string(count); 
            }
        }
        return res;
    }
    
    
    int getCount(string formula, int& s) {
        int num = 0;
        while (s<formula.size() && isdigit(formula[s])) {
            num = num*10 + formula[s] - '0';
            s++;
        }
        return num==0 ? 1:num;
    }
    
    string getName(string formula, int& s) {
        string name(1, formula[s]);
        s++;
        while (s<formula.size() && islower(formula[s])) {
            name = name + formula[s];
            s++;
        }
        return name;
    }    
    
    map<string, int> helper(vector<int>& close, string formula, int l, int r) {
        map<string, int> map;
        int i = l;
        while (i<=r) {
            if (formula[i] =='(') {
                int e = close[i];
                auto sub_map = helper(close, formula, i+1, e-1);
                i = e+1;
                int multipler = getCount(formula, i);
                for (auto [name, count] : sub_map) {
                    map[name] += count * multipler;
                }
            } else if(isupper(formula[i])) {
                string name = getName(formula, i);
                int multipler = getCount(formula, i);
                map[name] += multipler;
                
            } else {
                assert(false);
            }
        }
        return map;
    }
};
