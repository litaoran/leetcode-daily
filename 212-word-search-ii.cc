class Solution {
public:
    // Leetcode using C++ doesn't care about the memory management.
    class TrieNode {
      public:  
        TrieNode() {
            is_end = false;
            count = 0;
            children = vector<TrieNode*>(26, nullptr);
        }
        bool is_end;
        int count = 0; // Need to add a counter so that we don't need to go into a TrieNode if all words under it has been found.
        vector<TrieNode*> children;
    }; 
    TrieNode* root;
    
    TrieNode* BuildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (auto word : words) {
            TrieNode* cur = root;
            for (int i=0;i<word.size();i++) {
                int idx = word[i] - 'a';    
                if (cur->children[idx]==nullptr) {
                    cur->children[idx] = new TrieNode();
                }
                cur = cur->children[idx];
                cur->count++;
            }
            cur->is_end = true;
        }
        return root;
    }
    
    void ReduceCount(string word) {
        TrieNode* cur = root;
        for (int i=0;i<word.size();i++) {
            int idx = word[i] - 'a';    
            cur = cur->children[idx];
            cur->count--;
        }
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, TrieNode* node, string word, unordered_set<string>& res) {
        if (x<0||x>=board.size()||y<0||y>=board[0].size() || visited[x][y]) return;
        
        char c = board[x][y];
        if (node->children[c-'a']==nullptr) return;
        if (node->children[c-'a']->count==0) {
            return;
        }
        
        node = node->children[c-'a'];
        word = word + board[x][y];
        if (node->is_end) {
            if (res.count(word)==0) {
                res.insert(word);
                ReduceCount(word);
            }
        }
        
        visited[x][y] = true;
        dfs(board, visited, x, y+1, node, word,  res);
        dfs(board, visited, x, y-1, node, word,  res);
        dfs(board, visited, x+1, y, node, word,  res);
        dfs(board, visited, x-1, y, node, word,  res);
        visited[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = BuildTrie(words);
        
        int m = board.size();
        int n = board[0].size();
        
        unordered_set<string> set;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                dfs(board, visited, i, j, root, "", set);
            }
        }
        
        return vector<string>(set.begin(), set.end());
    }
};
