#include<bits/stdc++.h>

using namespace std;

bool isCyclicBFS(int src, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) {
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto neighbour : adjList[front]) {
            if (visited[neighbour] == true && neighbour != parent[front]) {
                return true;
            }
            else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) {
    visited[node] = true;

    for (auto neighbour : adjList[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = isCyclicDFS(neighbour, node, adjList, visited);
            if (cycleDetected) {
                return true;
            }
        }
        else if (neighbour != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(i, -1, adjList, visited);
            if (ans) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string result = cycleDetection(edges, n, m);
    cout << "Cycle Detected: " << result << endl;

    return 0;
}
