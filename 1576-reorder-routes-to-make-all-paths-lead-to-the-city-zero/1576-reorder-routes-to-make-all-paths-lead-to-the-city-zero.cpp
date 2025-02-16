class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
        unordered_set<string> original_edges;
        
        // Construct the adjacency list and track original edges
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            original_edges.insert(to_string(a) + "," + to_string(b)); // Store as "a,b"
        }

        int changes = 0;
        vector<bool> visited(n, false);

        // BFS approach instead of DFS to avoid recursion overhead
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    // If edge was originally (node → neighbor), it needs to be reversed
                    if (original_edges.count(to_string(node) + "," + to_string(neighbor))) {
                        changes++;
                    }
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return changes;
    }
};