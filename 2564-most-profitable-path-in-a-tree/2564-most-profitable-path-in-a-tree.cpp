#include <vector>
#include <functional>
#include <climits>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // Calculate the number of vertices.
        int numVertices = edges.size() + 1;
        // Create an adjacency list for the graph.
        vector<vector<int>> graph(numVertices);
      
        // Convert the edge list into an adjacency list.
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].emplace_back(to);
            graph[to].emplace_back(from);
        }
      
        // Initialize the time-stamps vector with a default value of 'n' which is out of bounds.
        vector<int> timestamps(numVertices, numVertices);
      
        // Depth-first search to update the timestamps at which each node can be visited when started from Bob's location.
        function<bool(int, int, int)> dfsUpdateTimeStamps = [&](int vertex, int parent, int time) -> bool {
            if (vertex == 0) {
                timestamps[vertex] = time;
                return true;
            }
            for (int neighbor : graph[vertex]) {
                if (neighbor != parent && dfsUpdateTimeStamps(neighbor, vertex, time + 1)) {
                    timestamps[neighbor] = min(timestamps[neighbor], time + 1);
                    return true;
                }
            }
            return false;
        };
      
        // Run DFS from Bob's position to update the timestamps.
        dfsUpdateTimeStamps(bob, -1, 0);
        // Bob's position must have a timestamp of 0.
        timestamps[bob] = 0;
      
        // Variable to store the answer - maximum profit.
        int maximumProfit = INT_MIN;
      
        // Depth-first search to calculate the maximum possible profit while traversing the graph.
        function<void(int, int, int, int)> dfsCalculateProfit = [&](int vertex, int parent, int time, int profit) {
            // Increment the profit depending on the time relative to the timestamp.
            if (time == timestamps[vertex])
                profit += amount[vertex] / 2;
            else if (time < timestamps[vertex])
                profit += amount[vertex];
          
            // If it's a leaf node, update the maximum profit.
            if (graph[vertex].size() == 1 && graph[vertex][0] == parent) {
                maximumProfit = max(maximumProfit, profit);
                return;
            }
          
            // Continue DFS on adjacent nodes to explore further profit opportunities.
            for (int neighbor : graph[vertex])
                if (neighbor != parent) dfsCalculateProfit(neighbor, vertex, time + 1, profit);
        };
      
        // Start DFS from vertex 0 to calculate the profit.
        dfsCalculateProfit(0, -1, 0, 0);
      
        // Return the maximum calculated profit.
        return maximumProfit;
    }
};
