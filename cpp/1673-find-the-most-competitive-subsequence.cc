class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stack;
        
        for (int i=0;i<n;i++) {
            while (!stack.empty() && nums[i]<stack.back() && stack.size()+n-i-1>=k) {
                stack.pop_back();
            }
            
            if (stack.size() < k) {
                stack.push_back(nums[i]);    
            }
        }
        return stack;
    }
};
