class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    
        deque<int> q;
        deque<int> idx;
        
        int sum = 0;
        int res = INT_MAX;
        for (int i=0;i<A.size();i++) {
            sum+=A[i];
            if (sum>=K) res = min(res, i+1);
            
            // because of the increasing queue, we could just check the front element in the queue to see if it meets the requirement. 
            // Once it meets the requirement, we could just pop the front element out since there won't be a shorter subarray starting from the front element. 
            while (!q.empty() && (sum-q.front() >=K) ){
                res = min(res, i - idx.front() );
                q.pop_front();
                idx.pop_front();
            }
            
            // keeps an increasing queue
            while (!q.empty() && sum<=q.back()) {
                q.pop_back();
                idx.pop_back();
            }
            q.push_back(sum);
            idx.push_back(i);
        }
        return res==INT_MAX? -1 : res;
    }
};
