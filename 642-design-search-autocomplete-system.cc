class AutocompleteSystem {
public:
    
    class Node {
      public:
        Node() {
            children = vector<Node*>(128);
        }
        string sentence = "";
        unordered_map<string, int> freq;
        vector<Node*> children;
    };
    Node* root;
    Node* node;
    string cur_str = "";
    bool not_found = false;
    void insert(Node* cur, string s, int times, int idx) {
        if (idx==s.size()) {
            cur->sentence = s;
            return;
        }
        int next = s[idx];
        if (cur->children[next]==nullptr) {
            cur->children[next] = new Node();
        }
        cur->children[next]->freq[s]+=times;
        
        insert(cur->children[next], s, times, idx+1);
    }
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Node();
        node = root;
        for (int i=0;i<sentences.size();i++) {
            insert(root, sentences[i], times[i], 0);
        }
    }
    
    vector<string> input(char c) {
        if (c=='#') {
            insert(root, cur_str, 1, 0);
            node = root;
            not_found = false;
            cur_str = "";
            return {};
        }
        cur_str += c;
        int next = c;
        if (not_found) {return {};}
        if (node->children[next]==nullptr) {
            not_found = true;
            return {};
        }
        node = node->children[next];
        vector<string> res;
        auto cmp = [](pair<int, string>& p1, pair<int, string>& p2) {
            if (p1.first != p2.first) {
                return p1.first < p2.first;
            } else {
                return p1.second > p2.second;
            }
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> q(cmp); // max heap
        for (auto& [s, count] : node->freq) {
            q.push({count, s});
        }
        for (int i=0;i<3;i++) {
            if (!q.empty()) {
                res.push_back(q.top().second);
                q.pop();
            }
        }
        return res;
    }
};

