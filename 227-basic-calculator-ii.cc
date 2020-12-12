class Solution {
public:
    int calculate(string s) {
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        
        stack<char> ops;
        ops.push('+');
        stack<long> nums;
        long num = 0;
        for (int i=0;i<s.size();i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num*10 + c-'0';
            } 
            
            if (!isdigit(c) || i==s.size()-1) {
                if (ops.top()=='*') {
                    int new_num = nums.top() * num;
                    nums.pop();
                    ops.pop();
                    nums.push(new_num);
                } else if (ops.top()=='/')  {
                    int new_num = nums.top() / num;
                    nums.pop();
                    ops.pop();
                    nums.push(new_num);
                } else {
                    nums.push(num);
                }
             
                if (!isdigit(c) ) {
                    ops.push(c);
                }
                num = 0;
            }
        }

        int res = 0;
        while (!nums.empty()) {
            if (ops.top()=='+') {
                res += nums.top();
            }
            if (ops.top()=='-') {
                res -= nums.top();
            }            
            nums.pop();
            ops.pop();
        }
            
        return res;
    }
};
