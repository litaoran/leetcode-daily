class WordDictionary {
public:
    class TrieNode {
      public:
        TrieNode() {
            children = vector<TrieNode*>(26, nullptr);
        }
        
        string word = "";
        vector<TrieNode*> children;
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    TrieNode* root;
    
    void addWord(string word) {
        addWordDfs(root, 0, word);
    }
    void addWordDfs(TrieNode* node, int idx, string word) {
        if (idx==word.size()) {
            node->word = word;
            return;
        }
        
        int next = word[idx]-'a';
        if (node->children[next]==nullptr) {
            node->children[next] = new TrieNode();
        }
        
        addWordDfs(node->children[next], idx+1, word);
    }
    
    bool search(string word) {
        return searchWordDfs(root, 0, word);
    }
    bool searchWordDfs(TrieNode* node, int idx, string word) {
        if (node==nullptr) {return false;}
        if (idx==word.size()) {
            if (!node->word.empty()) {
                return true;
            } else {
                return false;
            }
        }
        
        char c = word[idx];
        if (c=='.') {
            for (auto child : node->children) {
                bool found = searchWordDfs(child, idx+1, word);
                if (found) {return true;}
            }
            return false;
        } else {
            int next = c-'a';
            return searchWordDfs(node->children[next], idx+1, word);
        }
    }
};
