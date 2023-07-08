#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& edges, int src) {
    // Creating an adjacency list to represent the graph
    unordered_map<int, list<int>> adjList;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Initializing distance vector with a large value for all nodes
    vector<int> dist(n + 1, 1e9);

    queue<int> q;
    dist[src] = 0; // Distance from source to itself is 0
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto it : adjList[front]) {
            if (dist[front] + 1 < dist[it]) {
                dist[it] = dist[front] + 1;
                q.push(it);
            }
        }
    }

    vector<int> ans(n, -1);

    // Updating the answer vector with the shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main() {
    // Example input values
    int n = 6; // Number of nodes in the graph
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}}; // Edges in the graph
    int src = 0; // Source node for shortest path calculation

    vector<int> result = shortestPath(n, edges, src);

    // Printing the shortest distances from the source node
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Distance to node " << i << ": " << result[i] << endl;
    }

    return 0;
}
