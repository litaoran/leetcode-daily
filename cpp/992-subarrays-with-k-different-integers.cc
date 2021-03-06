class Solution {
public:
    // convert to classical sliding window problems.
    // "exactly(K) = atMost(K) - atMost(K-1)"
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K-1);
    }
    
    int helper(vector<int>& A, int K) {
        unordered_map<int, int> freq;
        int unique = 0;
        int i = 0;
        int res = 0;
        for (int j=0;j<A.size();j++) {
            freq[A[j]]++;
            if (freq[A[j]]==1) unique++;
            
            while (unique > K) {
                freq[A[i]]--;
                if (freq[A[i]] ==0) {
                    unique--;
                    freq.erase(A[i]);
                }
                i++;
            }
            res += j-i+1;
            
        }
        return res;
    }
};
