class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {   
        deque<int> q;
        deque<int> idx;

        vector<int> res;
        for (int i=0;i<nums.size();i++) {
        
            if (q.empty()) {
                q.push_back(nums[i]);
                idx.push_back(i);
            } else {
                while (!q.empty() && nums[i]>= q.back()) {
                    q.pop_back();
                    idx.pop_back();
                }
                q.push_back(nums[i]);
                idx.push_back(i);
            }
            
            
            if (i>=k-1) {
                while (i-idx.front()>=k) {
                    q.pop_front();
                    idx.pop_front();
                }
                
                res.push_back(q.front());
            }
            
        }
        return res;
    }
};
