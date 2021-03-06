class Solution {
public:
    int calculate(string s) {
        // o1: 1 means '+',  -1 means '-'
        // o2: 1 means '*',  -1 means '/'
        // l2: level-2 result. Calculated right after passing the number
        // l1: level-1 results. Calculated after we meet the next level-1 operator('+' or '-').
        
        stack<long> q;
        long num = 0;
        long l1 = 0, o1 = 1;
        long l2 = 1, o2 = 1;
        for (int i=0;i<s.size();i++) {
            
            char c = s[i];
            if (isdigit(c)) {
                num = c-'0';
                while (i!=s.size()-1 &&  isdigit(s[i+1])) {
                    num = num*10+ (s[i+1] - '0');
                    i++;
                }       
                l2 = (o2==1? l2*num : l2/num); 
            } else if (c=='(') {
                q.push(l1);   l1 =0;
                q.push(o1);   o1 =1;
                q.push(l2);   l2 =1;
                q.push(o2);   o2 =1;
            } else if (c==')') {
                l1 += o1*l2;
                long tmp = l1;
                o2 = q.top(); q.pop();
                l2 = q.top(); q.pop();
                o1 = q.top(); q.pop();
                l1 = q.top(); q.pop();
                
                l2 = (o2==1? l2*tmp : l2/tmp); 

            } else if (c=='*' || c=='/') {
                o2 = (c=='*'? 1:-1);
            } else if (c=='+' || c=='-') {
                l1 += o1*l2;
                o1 = (c=='+'? 1 : -1);
                l2 = 1; o2 = 1;
            }
        }
        
        return l1 + o1*l2;
    }
};
