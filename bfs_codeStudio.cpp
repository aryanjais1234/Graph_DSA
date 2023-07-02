/*Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2 */


#include <bits/stdc++.h> 

using namespace std;

// Function to prepare the adjacency list representation of the graph
void preparedAdjList(unordered_map<int, set<int>>& adjList, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        // Add an edge between u and v
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

// Breadth-First Search (BFS) function
void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Store the frontNode into ans
        ans.push_back(frontNode);

        // Traverse all neighbors of frontNode
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Prepare the adjacency list representation of the graph
    preparedAdjList(adjList, edges);

    // Traverse all components of the graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            // Perform BFS on unvisited nodes
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main() {
    int vertex, edgesCount;
    cin >> vertex >> edgesCount;

    vector<pair<int, int>> edges;
    for (int i = 0; i < edgesCount; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    vector<int> result = BFS(vertex, edges);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
