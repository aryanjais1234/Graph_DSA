#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n + 1);  // Create an adjacency list

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adjList[u].push_back(v);
    }

    vector<int> indegree(n + 1, 0);  // Initialize the indegree vector

    for (auto i : adjList) {
        for (auto j : i) {
            indegree[j]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        count++;

        for (auto neighbour : adjList[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    if (count == n) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n = 5;  // Number of nodes
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {5, 4}};  // Edges

    bool hasCycle = detectCycleInDirectedGraph(n, edges);

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
