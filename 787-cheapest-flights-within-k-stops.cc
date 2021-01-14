class Solution {
public:
    // Dynamic programming.  Time complexity O(N*K)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, unordered_map<int, int>> prices; // from dst to src
        for (auto f : flights) {
            prices[f[1]][f[0]] = f[2];
        } 
        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));  // dp[i][j]:  Distance to reach i with at most j stops.
        dp[0][src] = 0; 
        for (int i=1;i<=K+1;i++) {
            for (int j=0;j<n;j++) {
                dp[i][j] = dp[i-1][j];
                for (auto& [prev, price] : prices[j]) {
                    if (dp[i-1][prev]==INT_MAX) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][prev] + price);
                }
            }  
        }
        
        return dp[K+1][dst]==INT_MAX? -1 : dp[K+1][dst];     
    }

//         // Bellman Ford Algorithm
//         int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
            
//             vector<int> dist(n, INT_MAX); 
//             dist[src] = 0;
//             for (int i = 1; i <= K+1; i++) { 
//                 vector<int> tmp = dist;
//                  for (int j = 0; j < flights.size(); j++) { 
//                      int u = flights[j][0]; 
//                      int v = flights[j][1];
//                      int weight = flights[j][2];
//                      if (dist[u] != INT_MAX && dist[u] + weight < tmp[v]) {
//                          tmp[v] = dist[u] + weight; 
//                      }
//                  } 
//                 dist = tmp;
//             } 
            
//              return dist[dst]==INT_MAX? -1:dist[dst];
//         }
    
//     // special DFS that nodes could be revisted. 
//     int ans = INT_MAX;
//     void dfs(unordered_map<int, unordered_map<int, int>>& prices, int cur, int dst, int cost, int k) {
//         if (cur==dst) {
//             ans = min(ans, cost);
//             return;
//         }
//         if (k==0) return;
        
//         for (auto& [next, price] : prices[cur]) {
//             if (cost + price>= ans) continue;
//             dfs(prices, next, dst, cost+price, k-1);
//         }
//     }
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         unordered_map<int, unordered_map<int, int>> prices; // from dst to src
//         for (auto f : flights) {
//             prices[f[0]][f[1]] = f[2];
//         }
//         dfs(prices, src, dst, 0, K+1);   
//         return ans==INT_MAX?-1:ans;
//     }
    
    
//     // special BFS that nodes could be revisted. 
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         unordered_map<int, unordered_map<int, int>> prices; // from dst to src
//         for (auto f : flights) {
//             prices[f[0]][f[1]] = f[2];
//         }
        
//         int res = INT_MAX;
//         queue<pair<int,int>> q;
//         q.push({src, 0}); // {city, cost}
//         int step = -1;
//         while (!q.empty()) {
//             int len = q.size();
//             for (int i=0;i<len;i++) {
//                 pair<int, int> cur = q.front(); q.pop();
                
//                 int city = cur.first; int cost = cur.second;
//                 if (city==dst) { 
//                     res= min(res, cost); 
//                 }
                
//                 for (auto& [next, price] : prices[city]) {
//                     if (cost + price>= res) continue;
//                     q.push({next, cost+price});    
//                 }
//             }

//             step++;
//             if (step == K+1) { break;}
//         }
//         return res==INT_MAX? -1:res;     
//     }
};
