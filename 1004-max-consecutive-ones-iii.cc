class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = INT_MIN;
        
        int i=0;  int j=0; 
        int count =0;
        
        while (j < A.size()) {
            if (A[j] ==0) { // one more step to break the condition
                count++;
            }
            j++;
            
            while (i<j && count>K) {  // keep moving the left pointer until the window still meet the condition.
                if (A[i]==0) {
                    count--;
                }
                i++;
            }
            res = max(res, j-i);
        }
        return res;
    }
};
