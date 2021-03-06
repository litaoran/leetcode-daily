class Solution {
public:
    
    class Node {
      public:
        Node() {
            children = vector<Node*>(2);
        }
        
        bool exist = false;
        int num = 0;
        vector<Node*> children;
    };
    
    Node* root;
    
    // 31 bit:  30 -> 0
    void insert(Node* cur, int num, int idx) {
        if (idx<0) {
            // exist = true;    
            cur->num = num;
            return;
        }
        
        int val = num & (1<<idx);
        val = val==0?0:1;
        if (cur->children[val]==nullptr) {
            cur->children[val] = new Node();
        }
        insert(cur->children[val], num, idx-1);
    }
    
    int find(Node* cur, int x, int idx) {
        if (idx<0) {
            return x ^ cur->num;
        }
        
        if ((x & (1<<idx)) !=0) {
            if (cur->children[0]!=nullptr) {
                return find(cur->children[0], x, idx-1);
            } else if (cur->children[1]!=nullptr){
                return find(cur->children[1], x, idx-1);
            } else {
                return INT_MIN;
            }
        } else {
            if (cur->children[1]!=nullptr) {
                return find(cur->children[1], x, idx-1);
            } else if (cur->children[0]!=nullptr) {
                return find(cur->children[0], x, idx-1);
            } else {
                return INT_MIN;
            }
        }
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for (int i=0;i<queries.size();i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& v1, vector<int>& v2){ return v1[1] < v2[1];} );
        
        root = new Node();
        int i= 0;
        
        vector<int> res(queries.size());
        for (auto& query : queries) {
            int x = query[0]; int m = query[1];  
            while (i<nums.size() && nums[i]<=m) {
                insert(root, nums[i], 30);
                i++;
            }
            
            int cur = find(root, x, 30);
            cur = (cur==INT_MIN? -1 : cur);
            res[query[2]] = (cur==INT_MIN? -1 : cur);
        }
        return res;
        
    }
};
