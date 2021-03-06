class Solution {
public:
    int searchLeft(vector<int>& arr, int s, int e) {
        int l = s; int r =e;
        
        int val = arr[e];
        while (l<r) {
            int mid = l + (r-l)/2;
            
            if (arr[mid] != val) {
                l = mid+1;    
            } else {
                r= mid;
            }
        }
        return l;
    }
    
    int searchRight(vector<int>& arr, int s, int e) {
        int l = s; int r =e;
        
        
        int val = arr[s];
        while (l<r) {
            int mid = l + (r-l+1)/2;
            
            if (arr[mid] != val) {
                r = mid-1;    
            } else {
                l = mid;
            }
        }
        return l;
    }    
    
    // Using binary search to find the boundary.
    int findSpecialInteger(vector<int>& arr) {
        if (arr.size() <= 3) {
            return arr[0];
        }
        
        
        int n = arr.size()/4;
        int s = 0;
        int e = s+n-1;
        while (e<arr.size()) {                
            int l_boundary = searchLeft(arr, s, e);     
            int r_boundary = searchRight(arr, e, min(e+n, (int)arr.size()-1 ));  
            int size = r_boundary - l_boundary + 1;
            if (size > n) { return arr[e]; }
            
            s += n;
            e += n; 
        }
        return -1;
    }
};
