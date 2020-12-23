class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> left(26, 0);
        for (auto tile : tiles) {
            left[tile-'A']++;
        }
        return dfs(left);
    }
    
    
    int dfs(vector<int>& left) {
        
        int res = 0;
        for (int i=0;i<26;i++) {
            if (left[i]>0) {
                res++;
                left[i]--;
                res += dfs(left);
                left[i]++;
            }
        } 
        
        return res;
    }
    
};
