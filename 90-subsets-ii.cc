class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        queue<vector<int>> q;
        q.push({});
        
        sort(nums.begin(), nums.end());
        
        int i=0;
        while (i<nums.size()) {
            int count = 1;
            while (i!=nums.size()-1 && nums[i]==nums[i+1]) {
                i++;
                count++;
            }
            int len = q.size();
            for (int j=0;j<len;j++) {
                auto cur = q.front(); q.pop();
                for (int k=0;k<=count;k++) {
                    q.push(cur);
                    cur.push_back(nums[i]);
                }
            }
            i++;
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};
