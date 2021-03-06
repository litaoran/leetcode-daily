class StockSpanner {
public:
    stack<int> s;
    stack<int> s_idx;
    int cnt = 0;
    StockSpanner() {
        s.push(0); // placeholder
        s_idx.push(-1);
    }
    
    int next(int price) {
        while (s.size()>1 && price>=s.top()) {
            s.pop();
            s_idx.pop();
        }
        
        int res = cnt - s_idx.top();
        
        s.push(price);
        s_idx.push(cnt);
        cnt++;
        return res;
        
    }
};
