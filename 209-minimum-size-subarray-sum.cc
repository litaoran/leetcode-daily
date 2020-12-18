class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int b =0;
        int e =0;
        
        int res = INT_MAX;
        int sum = 0;
        while (e<nums.size()) {
            sum+= nums[e];
            e++;
             
            while (sum>=s ) {
                res = min(res, e-b);    
                sum-= nums[b];
                b++;                
            }
        }
        
        return res==INT_MAX? 0 : res;    
    }
};
