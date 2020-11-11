class Solution {
public:
    // exponential time complexity
    vector<int> res;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, vector<int>> s2p;
        for (int i=0;i<people.size();i++) {
            for (auto s : people[i]) {
                 s2p[s].push_back(i);
            }
        }
        
        unordered_set<int> team;
        helper(0, req_skills, s2p, team);
        return res;
    }
    
    void helper(int idx, vector<string>& req_skills, unordered_map<string, vector<int>>& s2p, unordered_set<int>& team) {
        // optimization 
        if (!res.empty() && team.size() >= res.size()) {
            return;
        }
        if (idx == req_skills.size()) {
            res = vector(team.begin(), team.end());
            return;
        }
        
        string s = req_skills[idx];
        for (auto p : s2p[s]) {
            bool p_exist = (team.count(p) != 0);
            team.insert(p);
            helper(idx+1, req_skills, s2p, team);
            if (!p_exist) {
                team.erase(p);
            }
        }
    }
    
};
