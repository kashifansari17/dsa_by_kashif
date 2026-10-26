#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS se current city se connected cities visit karenge
    void dfs(int city, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {

        visited[city] = true;  // Current city ko visited mark karo

        // Current city ke saare neighbours check karo
        for (int nextCity : adj[city]) {

            // Agar neighbour pehle visit nahi hua
            if (!visited[nextCity]) {
                dfs(nextCity, adj, visited);
                // Neighbour se aage DFS chalao
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Adjacency list banane ke liye unordered_map use karo
        unordered_map<int, vector<int>> adj;

        // Matrix ko adjacency list mein convert karo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Agar dono cities connected hain
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int provinces = 0;

        // Har city ko check karo
        for (int city = 0; city < n; city++) {

            // Unvisited city ek nayi province start karti hai
            if (!visited[city]) {
                provinces++;

                // Connected cities ko DFS se visit karo
                dfs(city, adj, visited);
            }
        }

        return provinces;  // Total provinces return karo
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;

    return 0;
}