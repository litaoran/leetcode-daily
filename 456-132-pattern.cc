class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        int s3 = INT_MIN;
        stack<int> s; // decreasing stack
        for (int i=n-1;i>=0;i--) {
        
            if (nums[i]<s3) {
                return true;
            }    
            while (!s.empty() && nums[i] > s.top()) {
                s3 = s.top(); s.pop();
            }
            s.push(nums[i]);
            
        }
        return false;        
    }
};
