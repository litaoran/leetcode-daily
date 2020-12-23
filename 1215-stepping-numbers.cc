class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        
        for (int i=0;i<=9;i++) {
            helper(i, low, high, res);    
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void helper(long cur, int low, int high, vector<int>& res) {
        if (cur > high) {
            return ;
        }
        
        if  (cur >= low && cur <=high) { res.push_back(cur); }
        
        if (cur==0) {return;}
        
        
        if (cur<10) {
            helper(cur*10+cur-1, low, high, res);
            if (cur+1<10) {
                helper(cur*10+cur+1, low, high, res);    
            }
        } else {
            int last = cur%10;
            int second_last = cur%100/10;
            
            if (last + 1<10) {
                helper(cur*10+last+1, low, high, res);
            }
            if (last - 1>=0) {
                helper(cur*10+last-1, low, high, res);
            }
        }     
    }
};
