#include<bits/stdc++.h>
using namespace std;
#define  inf 2e18
#define ll long long int
#define pb push_back


void dfs(vector<vector<int> > &G, vector<int> &ans, vector<bool> &visited, int a) {
	vis[a] = true;
	for (int u : G[a])
		if (!vis[u])
			dfs(G, ans, visited, u);
	ans.pb(u);
}

vetor<int> topological_sort(vector<vector<int> > &G, vector<int> &ans, vector<bool> &visited)
{
	ans.clear();
	visited.assign(n + 1, false);
	for (int i = 1; i <= v; i++)
		if (!vis[i])
			dfs(G, ans, vis, i);

	reverse(ans.begin(), ans.end());
	return ans;
}