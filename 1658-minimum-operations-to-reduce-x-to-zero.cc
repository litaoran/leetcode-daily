class Solution {
public:
    // Instead of find x, we find a subarray with sum:  Sum-x
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if (Sum<x) return -1;
        if (Sum==x) return nums.size();
        int t = Sum - x;
        
        
        int res = INT_MAX;
        
        int i=0;
        int total = 0;
        for (int j=0;j<n;j++) {
            total += nums[j];
            
            while (total >=t) {
                if (total == t) {
                    res = min(res, n - (j-i+1) );
                }
                total -= nums[i];
                i++;
            } 
        }
        
        return  res==INT_MAX? -1 : res;
    }
};
