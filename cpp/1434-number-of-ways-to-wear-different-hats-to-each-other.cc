class Solution {
public:
    const int mod = 1e9+7;
    const int hat_max = 40;
    
    // Assign people to hats.
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size(); // n person
        vector<vector<int>> hatToPeople(hat_max, vector<int>());
        vector<vector<int>> dp(hat_max, vector<int>(1<<n,-1));
        
        for (int i=0;i<n;i++) {
            for (int hat : hats[i]) {
                hatToPeople[hat-1].push_back(i);
            }
        }
                
        int AllMask =  (1<<n)-1;
        return helper(hatToPeople, dp, AllMask,  0,  0);
    }
    
    
    int helper(vector<vector<int>>& hatToPeople, vector<vector<int>>& dp, int& AllMask,   int i, int chosen_person) {
        if (chosen_person ==  AllMask ) {return 1;}
        if (i>=hat_max) {return 0;}
        if (dp[i][chosen_person]!=-1) {return dp[i][chosen_person];}

        int res = 0;
        // for each hat, we need to decide whether to choose it or not.
        // if skip:
        res += helper(hatToPeople, dp, AllMask, i+1, chosen_person);

        // if choose:
        for (int k : hatToPeople[i]) {
            if (((chosen_person >> k) & 1) == 1) {
                continue;
            }            

            res += helper(hatToPeople, dp, AllMask, i+1, (chosen_person|(1<<k)));
            res %= mod;                     
        }
        
        dp[i][chosen_person] = res;
        return res;
    }
};

