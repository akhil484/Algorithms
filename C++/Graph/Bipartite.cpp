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

vector<vector<int> > G;
int col[100005];

bool  isBipartite(int u)
{
	col[u] = 0;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int v : G[a])
		{
			if (col[v] == -1)
			{
				col[v] = 1 - col[a];
				q.push(v);
			}
			else if (col[v] == col[a])
				return false;
		}
	}
	return true;
}

int main()
{

	ll n, m;
	cin >> n >> m;
	G.resize(n + 1);
	bool p = true, s, r;
	vi v, res;
	for0(i, m)
	{
		int a, b;

		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);

	}
	for (int i = 1; i <= n; i++)
		col[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		if (col[i] == -1)
		{
			if (!isBipartite(i))
			{

				p = false;
				break;
			}
		}
	}
	if (!p)
		cout << "NOT BIPARTITE" << endl;
	else {
		ll cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (col[i] == 0) {
				cnt0++;
				v.pb(i);
			}
			else if (col[i] == 1)
			{
				cnt1++;
				res.pb(i);
			}

		}
		cout << cnt0 << endl;
		for0(i, v.size())
		cout << v[i] << " ";

		cout << endl;

		cout << cnt1 << endl;
		for0(i, res.size())
		cout << res[i] << " ";
	}

	return 0;
}