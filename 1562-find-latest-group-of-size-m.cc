class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        unordered_map<int, int> left;   // range [a,b]  b->a find left boundary for given key
        unordered_map<int, int> right;  // range [a,b]  a->b find right boundary for given key
        unordered_map<int, int> freq;
        
        int step = 0;
        int res = -1;
        for (int i=0;i<arr.size();i++) {
            step++;   
            int val = arr[i];
            int left_boundary = val;
            int right_boundary = val;
            if (val>1) {
                if (left.count(val-1) != 0) {
                    left_boundary = left[val-1];
                    left.erase(val-1);
                    right.erase(left_boundary);
                    freq[val-left_boundary]--;
                }
            }
            
            if (val<n) {
                if (right.count(val+1) != 0) {
                    right_boundary = right[val+1];
                    right.erase(val+1);
                    left.erase(right_boundary);
                    freq[right_boundary-val]--;
                }
            }
            
            int len = right_boundary-left_boundary+1;
            freq[len]++;
            left[right_boundary] = left_boundary;
            right[left_boundary] = right_boundary;
            
            if (freq[m]!=0) {
                res = step;
            }

        }
        return res;
    }
};
