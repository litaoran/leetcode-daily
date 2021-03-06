class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<int> stack;
        
        vector<int> index(n, -1);
        
        for (int i=0;i<n;i++) {
            if (expression[i] == '(') {
                stack.push(i);
            }
            
            if (expression[i] == ')') {
                int s = stack.top(); stack.pop();
                index[s] = i;
            }
        }
        return evaluate(index, expression, 0, n-1);
        
    }
    
    bool evaluate(const vector<int>& index, string str, int l, int r) {
        if (l == r) {
            if (str[l] == 't') return true;
            else return false;
        }
        
        int o = str[l]; // logical operator
        l+=2;  r-=1;   // strip the  enclosing operator and parenthesis
        int i = l;
    
        // backtracking all subexpressions
        vector<bool> res;
        while (i<=r) {
            if (str[i]=='t' || str[i]=='f') {
                res.push_back(evaluate(index, str, i, i));
                i +=2;
            } else if (str[i]=='!' || str[i]=='&' || str[i]=='|') {
                int new_l = i;
                int new_r = index[i+1];
                res.push_back(evaluate(index, str, new_l, new_r));
                i = new_r+2;
            } else {
                assert(false);
            }
        }
        
        // evaluation process
        if (o =='!') {
            return !res[0];
        } else if (o =='&') {
            for (auto it : res) {
                if (it == false) {return false;}
            }
            return true;
        } else if (o =='|') {
            for (auto it : res) {
                if (it) {return true;}
            }
            return false;
        } else {
            assert(false);
        }
    }
};
