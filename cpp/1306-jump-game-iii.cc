class Solution {
public:
    // O(N): time complexity
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return helper(start, arr, visited);
    }
    
    bool helper(int cur, vector<int>& arr, vector<bool>& visited) {
        if (visited[cur]) {return false;}
        
        visited[cur] = true;
        
        int step = arr[cur];
        if (step ==0) {
            return true;
        }
        
        int idx1 = cur - step;
        int idx2 = cur + step;
        if (idx1>=0 && idx1 <arr.size() && visited[idx1]==false) {
            bool reach = helper(idx1, arr, visited);
            if (reach) return true;
        }
        
        if (idx2>=0 && idx2 <arr.size() && visited[idx2]==false) {
            bool reach = helper(idx2, arr, visited);
            if (reach) return true;
        }
        return false;
    }
};
