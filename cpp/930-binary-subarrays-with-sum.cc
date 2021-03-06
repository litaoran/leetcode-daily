class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        vector<int> P(n+1);
        for (int i=0;i<n;i++) {
            P[i+1]=P[i]+A[i];
        }
        
        int res = 0;
        unordered_map<int, int> map;
        map[0]=1; // placeholder;
        for (int i=0;i<n;i++) {
            res += map[P[i+1]-S];
            map[P[i+1]]++;  
        }
        return res;
        
    }
};

