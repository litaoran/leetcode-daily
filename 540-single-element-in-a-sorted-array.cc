class Solution {
public:
    
    // If it's a double element, move the idx to point to the left one.
    bool isSingle(vector<int>& nums, int& idx) {
        int val = nums[idx];
        if (idx==0) {
            if (nums[idx] == nums[idx+1]) {
                // do nothing
            } else {
                return true;
            }
        } else if (idx==nums.size()-1) {
            if (nums[idx] == nums[idx-1]) {
                // do nothing
            } else {
                return true;
            }
        } else {
            if (nums[idx] == nums[idx-1]) {
                idx = idx-1;
            } else if (nums[idx] == nums[idx+1]) {
            } else {
                return true;
            }
        }
        return false;
        
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0; int r = nums.size()-1;
        
        while (l<r) {
            int mid = l + (r-l)/2;
            if (isSingle(nums, mid)) {return nums[mid];}
            if (mid %2==0) {
                l = mid+2;
            } else {
                r = mid-1;
            }
        }
        
        return nums[l];
    }
};
