class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(nums);
        tmp.insert(tmp.end(), nums.begin(), nums.end());
        
        vector<int> next_max(tmp.size());
        
        stack<int> s;
        for (int i=tmp.size()-1;i>=0;i--) {
            while (!s.empty() && tmp[i]>=s.top()) {
                s.pop();
            }
            if (s.empty()) {
                next_max[i] = -1;
            } else {
                next_max[i] = s.top();   
            }
            s.push(tmp[i]);
        }
        next_max.resize(n);
        return next_max;
    }
    
};
