#include<bits/stdc++.h>
using namespace std;
bool checkCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited, unordered_map<int, list<int>>& adjList) {
  visited[node] = true;
  dfsvisited[node] = true;

  for (auto neighbour : adjList[node]) {
    if (!visited[neighbour]) {
      // Explore the unvisited neighbour recursively
      bool cycleDetected = checkCycleDFS(neighbour, visited, dfsvisited, adjList);
      if (cycleDetected) {
        return true;  // If a cycle is detected in the recursion, return true
      }
    }
    else if (dfsvisited[neighbour]) {
      return true;  // If the neighbour is already visited in the current DFS traversal, a cycle is detected
    }
  }

  dfsvisited[node] = false;  // Mark the node as not visited in the current DFS traversal
  return false;  // No cycle detected for the current node
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
  // Create an adjacency list to represent the directed graph
  unordered_map<int, list<int>> adjList;

  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    // Add the directed edge from 'u' to 'v' in the adjacency list
    adjList[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsvisited;

  for (int i = 0; i <= n; i++) {
    if (!visited[i]) {
      // Perform DFS traversal for each unvisited node
      bool cycleFound = checkCycleDFS(i, visited, dfsvisited, adjList);
      if (cycleFound) {
        return true;  // If a cycle is found in any DFS traversal, return true
      }
    }
  }

  return false;  // No cycle detected in the graph
}

int main() {
  int n = 4;  // Number of nodes in the graph
  vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 1}, {3, 4}};  // Directed edges in the graph

  bool hasCycle = detectCycleInDirectedGraph(n, edges);

  if (hasCycle) {
    cout << "The graph contains a cycle." << endl;
  }
  else {
    cout << "The graph does not contain a cycle." << endl;
  }

  return 0;
}
