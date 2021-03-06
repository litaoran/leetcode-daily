class Solution {
public:
    int getMissing(vector<int>& nums, int idx) {
        return nums[idx] - nums[0] - idx;
    }
    // the missing number should between l-th and r-th
    int missingElement(vector<int>& nums, int k) {
        
        int l = 0; int r = nums.size()-1;
        
        while (l+1<r) {
            int mid = l + (r-l)/2;
            int missed = getMissing(nums, mid);        
            
            if (missed<k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        
        if (getMissing(nums, l)<k && getMissing(nums, r)>=k) {
            return nums[l] + k- getMissing(nums, l);
        } else {
            return nums[r] + k- getMissing(nums, r);
        }
    }
};
