class Solution {
public:
    // Monotonic Stack. O(n)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> map;
        
        stack<int> s;
        vector<int> greater(n, -1);
        for (int i=n-1;i>=0;i--) {
            if (s.empty()) {
                s.push(nums2[i]);
            } else {
                while (!s.empty() && nums2[i] > s.top()) {
                    s.pop();
                }
                
                if (!s.empty()) {
                    greater[i] = s.top();
                }
                s.push(nums2[i]);
            }
            map[nums2[i]]=i;
        }
        vector<int> res(m);
        for (int i=0;i<m;i++) {
            res[i] = greater[map[nums1[i]]];
        }
        return res;
    }
    
    
    // // O(N^2)
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     unordered_map<int, int> map;
    //     for (int i=0;i<nums2.size();i++) {
    //         map[nums2[i]]=i;
    //     }
    //     vector<int> res(n, -1);
    //     for (int i=0;i<n;i++) {
    //         int idx = map[nums1[i]];
    //         for (int j=idx+1;j<nums2.size();j++) {
    //             if (nums2[j] > nums1[i]) {
    //                 res[i] = nums2[j];
    //                 break;
    //             }
    //         }
    //     }
    //     return res;
    // }
};
