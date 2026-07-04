#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Build the Adjacency List
        // Each node maps to a list of pairs: {neighbor, road_distance}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist}); // Bidirectional
        }

        // Step 2: Initialize structures for BFS
        int min_score = INT_MAX;      // Track the smallest edge found
        vector<bool> visited(n + 1, false); // Prevent infinite loops
        queue<int> q;

        // Start BFS from City 1
        q.push(1);
        visited[1] = true;

        // Step 3: Standard BFS Loop
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Check all roads connected to the current city
            for (const auto& edge : adj[curr]) {
                int neighbor = edge.first;
                int dist = edge.second;

                // Update the global minimum score with this road's weight
                min_score = min(min_score, dist);

                // If neighbor hasn't been visited, add it to the queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return min_score;
    }
};

