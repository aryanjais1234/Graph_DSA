/*Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 48*/



#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

void prepareAdjlist(unordered_map<int, list<int>>& adjList, vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add edge u->v and v->u to the adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adjList, vector<int>& component) {
    // Add the current node to the component vector
    component.push_back(node);
    visited[node] = true;

    // Visit all neighbors of the current node
    for (auto i : adjList[node]) {
        if (!visited[i]) {
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adjList;
    prepareAdjlist(adjList, edges);
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    // Traverse all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    // Input the edges of the graph
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Perform Depth First Search (DFS)
    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    // Output the components obtained from DFS
    cout<<components.size()<<endl;
    for (auto component : components) {
        for (auto node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
