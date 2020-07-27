#include <bits/stdc++.h>
using namespace std;
#define  deb1(x) cerr<<#x<<": "<<x<<" "<<endl
#define ll long long int
#define pb push_back

vector<vector<int> > G;
const int M = 21;
int par[100005][M], depth[100005];

void dfs(int curr, int parent)
{
	for (auto x : G[curr])
	{
		if (x != parent) {
			depth[x] = depth[curr] + 1;
			dfs(x, curr);
		}
	}
	return ;
}

// O(n)*M
void calc_sparse_table(int curr, int parent)
{
	par[curr][0] = parent;
	for (int j = 1; j < M; j++)
	{
		par[curr][j] = par[par[curr][j - 1]][j - 1];
	}
	for (auto x : G[curr])
		if (x != parent)
			calc_sparse_table(x, curr);
}

// LCA Using Depth
// O(logn) =~O(M)
int LCA_using_depth(int u, int v)
{
	if (u == v)
		return u;
	if (depth[u] < depth[v])
		swap(u, v);

	int diff = depth[u] - depth[v];
	// Bring on same level
	for (int i = M - 1; i >= 0; i--)
	{
		if ((diff >> i) & 1)
		{
			u = par[u][i];
		}
	}
	// after this u and v are at same level;
	if (u == v)
		return u;

	for (int i = M - 1; i >= 0; i--)
	{
		if (par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0]; // or par[v][0] as I am standing on child of LCA
}

/* LCA Using time in and Out*/

/* In this we only move one node upto its ancestor until
	parent of that node is the ancestor of other too.*/

//	Calculating sparse table is common in both approach.

int timm = 0, timin[100005], timout[100005];

void dfs_time(int curr, int parent)
{
	timin[curr] = ++timm;
	for (auto x : G[curr])
	{
		if (x != parent) {
			dfs_time(x, curr);
		}
	}
	timout[curr] = timm;
}

bool is_ancestor(int u, int v)
{
	return timin[u] <= timin[v] && timout[u] >= timout[v];
}

// O(logn)
int LCA_using_time(int u, int v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;

	for (int i = M - 1; i >= 0; i--)
	{
		// we are moving only u
		if (!is_ancestor(par[u][i] , par[v][i]))
		{
			u = par[u][i];
		}
	}
	return par[u][0];
}

int main()
{
	int n, m;
	cin >> n >> m;
	G.resize(n + 1);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	// Assuming 1 is the root node of the tree.

	/*  Using only sparse table */

	// memset(depth, 0, sizeof(depth)); // global variables are by defalut intialized to 0.
	dfs(1, 0);
	calc_sparse_table(1, 0);

	cout << LCA_using_depth(9, 15) << endl;
	cout << LCA_using_depth(18, 15) << endl;
	cout << LCA_using_depth(15, 15) << endl;

	/* Using time in and out method along with sparse table */

	// memset(timin, 0, sizeof(timin)); // global variables are by defalut intialized to 0.
	// memset(timout, 0, sizeof(timout));
	timin[0] = 0; timout[0] = m + 1; // 0 is universal parent
	dfs_time(1, 0);
	calc_sparse_table(1, 0);
	cout << LCA_using_time(9, 15) << endl;
	cout << LCA_using_time(18, 15) << endl;
	cout << LCA_using_time(15, 15) << endl;

	return 0;
}