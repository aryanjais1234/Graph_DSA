#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
	
	// Create an adjacency list to represent the graph
	unordered_map<int, list<int>> adjList;
	for(auto edge : edges) {
		int u = edge.first;
		int v = edge.second;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// Perform BFS to find the shortest path from source 's' to target 't'
	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1, -1);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int front = q.front();
		q.pop();

		for(auto i : adjList[front]) {
			if(!visited[i]) {
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	// Reconstruct the shortest path from 's' to 't'
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s) {
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n, m;
	cout << "Enter the number of nodes: ";
	cin >> n;
	cout << "Enter the number of edges: ";
	cin >> m;
	
	vector<pair<int, int>> edges;
	cout << "Enter the edges (u v):" << endl;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	int s, t;
	cout << "Enter the source node: ";
	cin >> s;
	cout << "Enter the target node: ";
	cin >> t;

	vector<int> shortest_Path = shortestPath(edges,n,m,s,t);

	cout << "Shortest path from " << s << " to " << t << ": ";
	for(int node : shortest_Path)
		cout << node << " ";
	
	return 0;
}
