#include <bits/stdc++.h>
using namespace std;

bool check(unordered_map<int, vector<int>>& mp,
           int S, int D, vector<bool>& visited) {

    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Destination mil gaya
        if (node == D) {
            return true;
        }

        // Explore all neighbours
        for (auto &neighbor : mp[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Destination reachable nahi hai
    return false;
}

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

    unordered_map<int, vector<int>> mp;

    // Build undirected graph
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    vector<bool> visited(n, false);

    cout << boolalpha
         << check(mp, source, destination, visited)
         << endl;

    return 0;
}