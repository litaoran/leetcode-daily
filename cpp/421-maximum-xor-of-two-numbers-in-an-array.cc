class Solution {
public:
    // XOR property: a ^ b = c  =>   a = b ^ c
    int findMaximumXOR(vector<int>& nums) {
        unsigned int max = 0;
        unsigned int mask = 0;
        for (int i=31;i>=0;i--) {
            mask = mask | (1<<i);
            unordered_set<int> set;
            for (auto num : nums) {
                set.insert(num & mask);
            }
            // greedy. Try the next possible maximum number
            int cand = max | (1<<i);
            for (auto a : set) {
                if (set.count((cand ^ a)) !=0) {
                    max = cand;
                    break;
                }
            }
        }
        return max;
    }
};
