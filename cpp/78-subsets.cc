class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        queue<vector<int>> q;
        q.push({});
        
        for (int i=0;i<nums.size();i++) {
            int len = q.size();
            for (int j=0;j<len;j++) {
                auto cur = q.front(); q.pop();
                q.push(cur);
                auto new_vec = cur;
                new_vec.push_back(nums[i]);
                q.push(new_vec);
            }
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(move(q.front()));
            q.pop();
        }
        return res;
    }
};
