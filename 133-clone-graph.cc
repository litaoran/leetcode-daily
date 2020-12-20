class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {return nullptr;}
        
        unordered_map<Node*, Node*> map;
        
        return dfs(node, map);
    }
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        if (node == nullptr) { return nullptr;}
        if (map.count(node) != 0) { return map[node]; }
        
        map[node] = new Node(node->val);
        for (auto child : node->neighbors) {
            map[node]->neighbors.push_back(dfs(child, map));
        }
        
        return map[node];
    }
    
    
//     Node* cloneGraph(Node* node) {
//         if (node == nullptr) {return nullptr;}
        
//         unordered_map<Node*, Node*> map;
        
//         Node* clone = new Node(node->val);
//         dfs(node, clone, map);
        
//         return clone;    
//     }
//     void dfs(Node* node, Node* clone, unordered_map<Node*, Node*>& map) {
//         map[node] = clone; 
        
//         for (auto child : node->neighbors) {
//             if (map.count(child)!=0) {
//                 clone->neighbors.push_back(map[child]);
//             } else {
//                 Node* child_clone = new Node(child->val);
//                 clone->neighbors.push_back(child_clone);
//                 dfs(child, child_clone, map);
//             }
//         }        
//     }
};
