
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Current node se DFS perform karne wala helper
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& ans) {

        // Current node ko visited mark karo
        vis[node] = 1;

        // Traversal order mein node store karo
        ans.push_back(node);

        // Current node ke neighbours explore karo
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                // Unvisited neighbour ke andar depth mein jao
                dfs(nei, adj, vis, ans);
            }
        }
    }

public:
    // Node 0 se DFS traversal
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int> vis(V, 0);
        vector<int> ans;

        if (V > 0) {
            dfs(0, adj, vis, ans);
        }

        return ans;
    }
};

int main() {
    int V = 5;

    // Graph ki adjacency list
    vector<vector<int>> adj(V);

    // Undirected edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[2].push_back(4);
    adj[4].push_back(2);

    // DFS call
    Solution sol;
    vector<int> result = sol.dfsOfGraph(adj);

    // Answer print karo
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
