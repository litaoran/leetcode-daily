class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int limit) {
    
        deque<int> mind, maxd; // maxd is decreasing and mind is increasing.
        
        int i =0;
        int res = 0;
        for (int j=0;j<nums.size();j++) {
            while (!maxd.empty() && nums[j]>maxd.back()) {maxd.pop_back();}
            while (!mind.empty() && nums[j]<mind.back()) {mind.pop_back();}
            maxd.push_back(nums[j]);
            mind.push_back(nums[j]);
            
            while (maxd.front() - mind.front()> limit) {
                if (nums[i] == maxd.front()) {maxd.pop_front(); }
                if (nums[i] == mind.front()) {mind.pop_front(); }
                i++;
            }
            res = max(res, j-i+1);
        }
        
        return res;
    }
    
    
    
    // // Using multiset to keep the order. O(NLogN)
    // typedef pair<int, int> Pair;
    // int longestSubarray(vector<int>& nums, int limit) {
    //     int res = 0;
    //     multiset<int> set;
    //     int i = 0;
    //     for (int j=0;j<nums.size();j++) {
    //         set.insert(nums[j]);
    //         while (!set.empty() && *set.rbegin() - *set.begin()>limit ) {
    //             set.erase(set.find(nums[i]));
    //             i++;
    //         }
    //         res = max(res, j-i+1);
    //     }
    //     return res;
    // }
};
