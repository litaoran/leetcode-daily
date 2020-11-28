constexpr int mod = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        stack<int> s1;
        stack<int> s2;
        
        for(int i = 0; i < arr.size(); i++) left[i] = i + 1;
        for(int i = 0; i < arr.size(); i++) right[i] = n - i;     
        
        // Note how we handle the duplicate case.  The duplicate case is only considered in one direction so we don't double count the number.
        for (int i=0;i<n;i++) {
            while (!s1.empty() && arr[i]<=arr[s1.top()]) { 
                s1.pop();
            }
            if (!s1.empty()) {
                left[i] = i - s1.top();    
            }
            s1.push(i);
        }
        for (int i=n-1;i>=0;i--) {
            while (!s2.empty() && arr[i]<arr[s2.top()]) {
                s2.pop();
            }
            if (!s2.empty()) {
                right[i] = s2.top() - i;    
            }
            s2.push(i);
        }
        
        int sum = 0;
        for (int i=0;i<n;i++) {
            sum+= (long)left[i] *right[i] * arr[i]%mod; // If left[i] as d1, right[i] as d2, the total num of subarrays with idx i as the minimum element is (d1-1)*(d2-1)+(d1-1)+(d2-1)+1; 
            sum%=mod;
        }
        
        return sum;
    }
};
