#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int destination,
             vector<vector<int>>& adj,
             vector<int>& visited) {

        // Base case: destination mil gaya
        if (node == destination) {
            return true;
        }

        // Mark current node as visited
        visited[node] = 1;

        // Explore all neighbours
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, adj, visited)) {
                    return true;
                }
            }
        }

        // Destination not found in this route
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        // Build an undirected adjacency list
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        return dfs(source, destination, adj, visited);
    }
};

int main() {
    int n = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {0, 4}
    };

    int source = 0;
    int destination = 3;

    Solution sol;

    bool result = sol.validPath(n, edges, source, destination);

    cout << boolalpha << result << endl;

    return 0;
}