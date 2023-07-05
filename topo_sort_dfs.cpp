#include <bits/stdc++.h> 
using namespace std;
void topoSort(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adjList) {
    visited[node] = true;

    for (auto neighbour : adjList[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adjList);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    // Create an adjacency list to represent the graph
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adjList);
        }
    }

    vector<int> ans;

    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter the edges (source -> destination): " << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Sort: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Check if the result is a valid topological sort
    bool isTopologicalSort = true;
    for (int i = 0; i < result.size(); i++) {
        int node = result[i];

        for (auto neighbour : edges) {
            if (neighbour[0] == node) {
                // If there is an edge from the current node to any other node in the result,
                // it is not a valid topological sort
                isTopologicalSort = false;
                break;
            }
        }
        if (!isTopologicalSort) {
            break;
        }
    }

    if (isTopologicalSort) {
        cout << "The result is a valid topological sort." << endl;
    } else {
        cout << "The result is not a valid topological sort." << endl;
    }

    return 0;
}
