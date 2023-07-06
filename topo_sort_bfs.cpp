#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    vector<vector<int>> adjList(v);  // Create an adjacency list

    // Construct the adjacency list
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
    }

    vector<int> indegree(v, 0);  // Initialize the indegree vector

    // Calculate the indegree for each node
    for (auto i : adjList) {
        for (auto j : i) {
            indegree[j]++;
        }
    }

    queue<int> q;

    // Push nodes with indegree 0 into the queue
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    // Perform topological sort
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        // Reduce the indegree of neighboring nodes and push nodes with indegree 0 into the queue
        for (auto neighbour : adjList[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main() {
    int v, e;  // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));  // 2D vector to store the edges
    cout << "Enter the edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> sortedOrder = topologicalSort(edges, v, e);

    cout << "Topological Sort: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
