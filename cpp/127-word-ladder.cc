class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end()); 
        
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        while (!q.empty()) {
            len++;
            int size = q.size();
            for (int i=0;i<size;i++) {
                string cur = q.front();  q.pop();
                if (cur==endWord) return len;
                
                for (int j=0;j<cur.size();j++) {
                    char c = cur[j];
                    for (int k=0;k<26;k++) {
                        char cc = k + 'a';
                        if (c==cc) continue;
                        cur[j] = cc;
                        if (set.count(cur)!=0) {
                            set.erase(cur);  
                            q.push(cur);
                        }
                    }    
                    cur[j] = c;
                }
            }
        }
        
        return 0;
        
    }
};
