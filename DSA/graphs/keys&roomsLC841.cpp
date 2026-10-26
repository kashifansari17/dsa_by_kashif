#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS se current room explore karenge
    void dfs(int room, vector<vector<int>>& rooms,
             vector<bool>& visited) {

        visited[room] = true;  // Current room ko visited mark karo

        // Current room mein available saari keys check karo
        for (int key : rooms[room]) {

            // Agar key wala room pehle visit nahi hua
            if (!visited[key]) {
                dfs(key, rooms, visited);  // Us room mein DFS chalao
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        // Shuru mein koi bhi room visited nahi hai
        vector<bool> visited(n, false);

        // Room 0 se DFS start karo
        dfs(0, rooms, visited);

        // Check karo ki koi room unvisited toh nahi reh gaya
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;  // Ek bhi room nahi mila toh false
            }
        }

        return true;  // Saare rooms visit ho gaye
    }
};

int main() {

    vector<vector<int>> rooms = {
        {1}, {2}, {3}, {}
    };

    Solution sol;

    // Function ka result print karo
    cout << boolalpha << sol.canVisitAllRooms(rooms) << endl;

    return 0;
}
///////////////////////////////////////bfs///////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        // Shuru mein saare rooms unvisited hain
        vector<bool> visited(n, false);

        queue<int> q;

        // Room 0 se BFS start karo
        q.push(0);
        visited[0] = true;

        // Jab tak queue mein rooms hain, process karo
        while (!q.empty()) {
            int room = q.front();  // Queue ka pehla room nikalo
            q.pop();

            // Current room mein available saari keys check karo
            for (int key : rooms[room]) {

                // Agar key wala room abhi tak visit nahi hua
                if (!visited[key]) {
                    visited[key] = true;  // Room ko visited mark karo
                    q.push(key);          // Room ko queue mein daalo
                }
            }
        }

        // Check karo ki saare rooms visit hue ya nahi
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;  // Koi room unvisited hai
            }
        }

        return true;  // Saare rooms visit ho gaye
    }
};

int main() {
    vector<vector<int>> rooms = {
        {1}, {2}, {3}, {}
    };

    Solution sol;

    // Result ko true ya false mein print karo
    cout << boolalpha << sol.canVisitAllRooms(rooms) << endl;

    return 0;
}