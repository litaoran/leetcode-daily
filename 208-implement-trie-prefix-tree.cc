class Trie {
public:
    /** Initialize your data structure here. */
    
    class Node {
      public:
        Node() {
            children = vector<Node*>(26);
        }
        
        string str = "";
        vector<Node*> children;
    };
    
    Node root;
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = &root;
        for (int i=0;i<word.size();i++) {
            int idx = word[i]-'a';
            if (cur->children[idx]==nullptr) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->str = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = &root;
        for (int i=0;i<word.size();i++) {
            int idx = word[i]-'a';
            if (cur->children[idx]==nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return !(cur->str.empty());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = &root;
        for (int i=0;i<prefix.size();i++) {
            int idx = prefix[i]-'a';
            if (cur->children[idx]==nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }
};
