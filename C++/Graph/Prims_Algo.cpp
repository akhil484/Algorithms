#include<bits/stdc++.h>
using namespace std;
#define  bg begin()
#define  en end()
#define  ll long long int
#define  pb push_back
#define  mp make_pair
#define  vi vector<int>
#define  for0(i,m) for(int i=0;i<m;i++)
#define  for1(i,m) for(int i=1;i<=m;i++)
#define  forv(it,v) for(auto it=v.begin();it!=v.end();it++)
#define  mem(a,val) memset(a,val,sizeof(a))
#define  deb1(x) cerr<<#x<<": "<<x<<" "<<endl
#define  deb2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define  deb3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define  deb4(a, b, ser, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#ser<<": "<<ser<<" | "<<#d<<": "<<d<<endl

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > G(n + 1);

	vector<bool> vis(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		G[x].pb({y, w});
		G[y].pb({x, w});
	}
	priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int> > > pq;

	int ans = 0;
	// {weight,node}
	pq.push({0, 1});
	// Push any vertex let it be 1 and initially weight be 0
	while (!pq.empty())
	{
		pair<int, int> best = pq.top();
		pq.pop();
		int weight = best.first;
		int to = best.second;

		// Already included in MST
		if (vis[to]) continue;

		ans += weight;
		vis[to] = true;
		for (auto x : G[to])
		{
			if (vis[x.first] == false)
			{
				// x.first is not visited
				pq.push({x.second, x.first});
			}
		}
	}
	cout << ans << endl;
	return 0;
}