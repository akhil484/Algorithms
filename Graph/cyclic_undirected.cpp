#include<bits/stdc++.h>
using namespace std;
bool is_cyclic(vector<vector<int> >&adjList, int n) {
	vector<int> mark(n, -1);
	queue<int> q;
	q.push(0);
	mark[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < adjList[v].size(); i++) {
			int nbs = adjList[v][i];
			if (mark[nbs] == -1) {
				q.push(nbs);
				mark[nbs] = 0;
			}
			else if (mark[nbs] == 0) return true;
		}
		mark[v] = 1;
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	if (is_cyclic(adjList, n)) cout << "It is a cyclic graph...." << endl;
	else cout << "Not a cyclic graph...." << endl;
}
