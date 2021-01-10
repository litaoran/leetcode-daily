class Solution {
public:
    vector<int> TSort(unordered_map<int, unordered_set<int>> dependents) {
        unordered_map<int, int> indegrees;
                
        for (auto& [key, val] : dependents) {
            indegrees[key];
            for (auto dependent : val) {
                indegrees[dependent]++;
            }
        }
        
        queue<int> q;
        for (auto& [i, indegree] : indegrees) {
            if (indegree==0) q.push(i);
        }
        
        vector<int> res;
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                int cur = q.front(); q.pop();
                res.push_back(cur);
                for (auto dependent : dependents[cur]) {
                    indegrees[dependent]--;
                    if (indegrees[dependent]==0) {
                        q.push(dependent);
                    }
                }
            }
        }
        
        return res.size()==indegrees.size() ? res : vector<int>();
    }
    
    
    vector<int> SelectedTSort(vector<vector<int>>& beforeItems, vector<int>& items) {
        
        unordered_set<int> items_set(items.begin(), items.end());
        unordered_map<int, unordered_set<int>> item_dependents;
        for (auto item : items) {item_dependents[item]; }
        
        for (int i=0;i<items.size();i++) {
            for (auto beforeitem : beforeItems[items[i]]) {
                if (items_set.count(beforeitem)!=0) {
                    item_dependents[beforeitem].insert(items[i]);
                }
            }
        }
        
        return TSort(item_dependents);
    }
    
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> group_items(m);
        unordered_map<int, int> item_group;
        unordered_map<int, unordered_set<int>> group_dependents;
        for (int i = 0; i < n; ++i) {
            if (group[i] >= 0) 
                group_items[group[i]].push_back(i);
            else {
                // Isolated items are put into separate groups.
                group[i] = group_items.size();
                group_items.push_back(vector<int>{i});
            }
            item_group[i] = group[i];
            group_dependents[group[i]];
        }
                
        for (int i=0;i<beforeItems.size();i++) {
            auto beforeitems = beforeItems[i];
            for (auto item : beforeitems) {
                if (item_group[item]==item_group[i]) {continue;}
                group_dependents[item_group[item]].insert(item_group[i]);
            }
        }
        
        vector<int> sort_group = TSort(group_dependents);        
        if (sort_group.empty()) return sort_group; // Check invalidity between groups
       
        vector<int> res;
        for (int i=0;i<sort_group.size();i++) {
            vector<int> items_in_group = SelectedTSort(beforeItems, group_items[sort_group[i]]);
            if (items_in_group.size() != group_items[sort_group[i]].size()) return vector<int>(); // Check invalidity within a group
            res.insert(res.end(), items_in_group.begin(), items_in_group.end());
        }
        return res;
    }
};
