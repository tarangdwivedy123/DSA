/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        
        // Create the clone for the starting node.
        Node* nodeClone = new Node(node->val);
        visited[node] = nodeClone;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            // Process each neighbor of the current node.
            for (auto neighbor : curr->neighbors) {
                // If neighbor has not been cloned, clone it.
                if (visited.find(neighbor) == visited.end()) {
                    Node* nebClone = new Node(neighbor->val);
                    visited[neighbor] = nebClone;
                    q.push(neighbor);
                }
                // Append the neighbor clone to the current clone's neighbors list.
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return nodeClone;
    }
};