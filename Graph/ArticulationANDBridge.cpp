#include <bits/stdc++.h>
using namespace std;
#define  deb1(x) cerr<<#x<<": "<<x<<" "<<endl
#define ll long long int
#define pb push_back

vector<vector<int> > G;
set<int> art_points;
vector<pair<int, int> > bridge;
int discovered[100005], lowest[100005] , timm;

void dfs(int cur, int par)
{
	discovered[cur] = lowest[cur] = timm++;
	int no_of_child = 0;
	for (auto child : G[cur])
	{
		// not visited
		if (discovered[child] == 0)
		{
			dfs(child, cur);
			no_of_child++;
			lowest[cur] = min(lowest[cur], lowest[child]);
			if (par != 0 && lowest[child] >= discovered[cur])
			{
				art_points.insert(cur);
			}
			if (lowest[child] > discovered[cur])
			{
				bridge.pb({cur, child});
			}
			if (par == 0 && no_of_child >= 2)
				art_points.insert(cur);
		}
		else if (child != par)
		{
			// backedge
			// cycle found
			lowest[cur] = min(lowest[cur], discovered[child]);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	G.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	timm = 1;
	memset(discovered, 0, sizeof(discovered));
	dfs(1, 0); // 1 is root and 0 is the parent of root
	cout << "Articulation Points : ";
	for (auto it = art_points.begin(); it != art_points.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "Bridge Edge : ";
	for (int i = 0; i < bridge.size(); i++)
		cout << bridge[i].first << "->" << bridge[i].second << " ";

	return 0;
}