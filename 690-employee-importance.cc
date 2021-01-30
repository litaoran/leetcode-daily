class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for (auto e : employees) {
            map[e->id] = e;
        }
        int res =0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            auto e = q.front(); q.pop();
            res += map[e]->importance;
            for (auto sub : map[e]->subordinates) {
                q.push(sub);
            }
        }
        return res;
    }
};
