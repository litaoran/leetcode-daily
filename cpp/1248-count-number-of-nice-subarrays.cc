class Solution {
public:
    // explanation: https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/508217/C%2B%2B%3A-Visual-explanation.-O(1)-space.-Two-pointers
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        
        int i = 0; int j = 0;
        int odd = 0;
        int count = 0;

        
        for (int j=0;j<n;j++) {
            if (nums[j] & 1) {
                odd++;
                count=0;
                while (odd>=k) {
                    count++;
                    if (nums[i]&1) {odd--;}
                    i++;
                    res += count;
                }
            } else {
                res += count;
            }
        }
        
        
        return res;
    }
};
