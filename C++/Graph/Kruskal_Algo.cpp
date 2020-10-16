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

map<int, int> par;
map<int, int>  rk;
void make_set(int n)
{
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		rk[i] = 1;
	}
	return;
}
int find(int x)
{
	if (x == par[x])
		return x;
	int p = find(par[x]);
	par[x] = p;
	return p;
}
void unite(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a == b)
		return;
	if (rk[a] >= rk[b])
	{
		par[b] = a; rk[a] += rk[b];
	}
	else
	{
		par[a] = b;
		rk[b] += rk[a];
	}
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector<int> > G(m);
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w; // edge going from x to y having weight w.
		G[i] = {w, x, y};
	}

	// Sort G on the basis of weight. So w was taken as first element in tuple.
	make_set(n);
	sort(G.begin(), G.end());
	int ans = 0;
	for (int i = 0; i < G.size(); i++)
	{
		int w = G[i][0];
		int x = G[i][1];
		int y = G[i][2];

		if (find(x) != find(y))
		{
			ans += w;
			unite(x, y);
		}
	}
	cout << ans << endl;
	return 0;
}