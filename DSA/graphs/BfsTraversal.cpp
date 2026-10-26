
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {

        // Step 1: Graph mein total nodes count karo
        int V = adj.size();

        // Step 2: Queue banao
        // Queue nodes ko FIFO order mein process karti hai
        queue<int> q;

        // Step 3: Visited array banao
        // 0 = unvisited, 1 = visited
        vector<int> vis(V, 0);

        // Step 4: BFS node 0 se start hoga
        // Pehle visited mark karo, phir queue mein daalo
        vis[0] = 1;
        q.push(0);

        // Step 5: Traversal ka answer store karne ke liye
        vector<int> ans;

        // Step 6: Jab tak queue empty nahi hoti
        while (!q.empty()) {

            // Queue ke front se node nikalo
            int node = q.front();
            q.pop();

            // Node ko BFS answer mein add karo
            ans.push_back(node);

            // Step 7: Current node ke neighbours check karo
            for (int nei : adj[node]) {

                // Agar neighbour abhi visit nahi hua
                if (!vis[nei]) {

                    // Visited mark karo taaki dobara add na ho
                    vis[nei] = 1;

                    // Neighbour ko future mein process karne ke liye
                    // queue mein daal do
                    q.push(nei);
                }
            }
        }

        // Step 8: BFS traversal return karo
        return ans;
    }
};

int main() {

    // Total vertices: 5 (0, 1, 2, 3, 4)
    int V = 5;

    // Adjacency list: har node ke neighbours
    vector<vector<int>> adj(V);

    // Undirected graph ki edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[2].push_back(4);
    adj[4].push_back(2);

    // Solution class ka object banao
    Solution sol;

    // BFS function call karo
    vector<int> result = sol.bfs(adj);

    // BFS traversal print karo
    cout << "BFS Traversal: ";

    for (int node : result) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
