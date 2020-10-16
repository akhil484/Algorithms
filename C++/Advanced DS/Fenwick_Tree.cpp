#include<bits/stdc++.h>
using namespace std;
#define  inf 2e18
#define ll long long int
int BIT[100005] = {0};
int querry( int i)
{
	int val = 0;
	while (i > 0)
	{
		val += BIT[i];
		i = i - (i & (-i));
	}
	return val;
}

void update(int n, int x, int inc)
{
	while (x <= n)
	{
		BIT[x] += inc;
		x = x + (x & (-x));
	}
}

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1];
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= n; i++)
			cin >> a[i];


		int ans = 0;
		for (int i = n; i >= 1; i--)
		{
			ans += querry( a[i] - 1);
			update(n, a[i], 1);
		}
		cout << ans << endl;
	}

	return 0;
}