class Solution {
public:
//     int minCostII(vector<vector<int>>& costs) {
//         if (costs.size()==0 || costs[0].size() ==0) {return 0;}
        
//         int k = costs[0].size();
//         if (k==1) {return costs[0][0];}
        
//         vector<int> dp(k);
//         for (int i=0;i<costs.size();i++) {
//             vector<int> new_cost(k);
            
//             int min_idx = min_element(dp.begin(), dp.end()) - dp.begin();
//             int second_min = INT_MAX;
//             for (int j=0;j<k;j++) {
//                 if (j==min_idx) {
//                     continue;
//                 }
//                 if (dp[j] < second_min) {second_min = dp[j];}
//             }
            
            
//             for (int j=0;j<k;j++) {
//                 if (j==min_idx) {
//                     new_cost[j] = costs[i][j] + second_min;
//                 } else {
//                     new_cost[j] = costs[i][j] + dp[min_idx];
//                 }
//             }
//             dp.swap(new_cost);
//         }
        
//         return *min_element(dp.begin(), dp.end());
//     }
    
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size()==0 || costs[0].size() ==0) {return 0;}
        
        int k = costs[0].size();
        if (k==1) {return costs[0][0];}
        
        int min1= 0; int min2 =0;
        int idx1=-1;
        
        for (int i=0;i<costs.size();i++) {
            
            int new_min1= INT_MAX; int new_min2 =INT_MAX;
            int new_idx1=-1;
            for (int j=0;j<k;j++) {
                int new_cost = costs[i][j] + (j==idx1? min2 : min1);
                
                if (new_cost <= new_min1) {
                    new_min2 = new_min1;
                    new_min1 = new_cost;
                    new_idx1 = j;
                } else if (new_cost < new_min2) {
                    new_min2 = new_cost;
                }
            }
            min1 = new_min1;
            min2 = new_min2;
            idx1 = new_idx1;
        }
        
        return min1;
    }    
};
