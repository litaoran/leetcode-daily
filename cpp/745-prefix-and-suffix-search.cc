class WordFilter {
public:
    class Node {
      public:
        Node() {
            children = vector<Node*>(26);
        }
        
        void add(string word, int pos, int idx) {
            idxes.push_back(idx);
            if (pos==word.size()) {
                return;
            }
            
            int next = word[pos] - 'a';
            if (children[next]==nullptr) {
                children[next] = new Node();
            }
            children[next]->add(word, pos+1, idx);
        }
        
        vector<int> search(string word, int pos) {
            if (pos == word.size()) {
                return idxes;
            }
            int next = word[pos] - 'a';
            if (children[next] == nullptr) {
                return {};
            } else {
                return children[next]->search(word, pos+1);
            }
        }

        
      private:
        vector<int> idxes;
        vector<Node*> children; 
    };
    
    WordFilter(vector<string>& words) {
        prefix_root = new Node();
        suffix_root = new Node();
        
        for (int i=0;i<words.size();i++) {
            prefix_root->add(words[i], 0, i);
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            suffix_root->add(tmp, 0, i);
        }
        
    }
    
    int f(string prefix, string suffix) {
        auto list1 = prefix_root->search(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        auto list2 = suffix_root->search(suffix, 0);
        auto it1 = list1.rbegin(); auto it2 = list2.rbegin();
        while (it1 != list1.rend() && it2!=list2.rend()) {
            if (*it1 == * it2) {
                return * it1;
            } else if (*it1 < *it2) {
                it2 = next(it2);
            } else {
                it1 = next(it1);
            }
        }
        return -1;
    
    }
    
    Node* prefix_root;
    Node* suffix_root;
};
