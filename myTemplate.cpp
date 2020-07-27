#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define  FIFO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define  inf 2e18
#define  mod 1000000007
#define  bg begin()
#define  en end()
#define  ll long long int
#define  pb push_back
#define  mp make_pair
#define  pii pair<int,int>
#define  pll pair<ll,ll>
#define  vi vector<int>
#define  vll vector<long long int>
#define  vpll vector<pair<long long int,long long int> >
#define  vpii vector<pair<int,int> >
#define  vstr vector<string>
#define  mpii map<int ,int>
#define  mpll map<long long int,long long int >
#define  max3(a,b,ser) max(a,max(b,ser))
#define  min3(a,b,ser) min(a,min(b,ser))
#define  setbits(x) __builtin_popcountll(x)
#define  zerobits(x) __builtinctzll(x) //zeros after rightmost set bit
#define  w(t) ll t; cin>>t; while(t--)
#define  vin(v,m) for(int i=0;i<m;i++){ll x;cin>>x; v.pb(x);}
#define  for0(i,m) for(int i=0;i<m;i++)
#define  for1(i,m) for(int i=1;i<=m;i++)
#define  forn(i,a,b) for(int i=a;i<=b;i++)
#define  forv(it,v) for(auto it=v.begin();it!=v.end();it++)
#define  mem(a,val) memset(a,val,sizeof(a))
#define  Sort(vec) sort(vec.begin(),vec.end())
#define  RSort(vec) sort(vec.rbegin(),vec.rend())
#define  eb emplace_back
#define  bs binary_search
#define  lb(v,a) lower_bound(v.begin(),v.end(),a)
#define  ub(v,a) upper_bound(v.begin(),v.end(),a)
#define  deb1(x) cerr<<#x<<": "<<x<<" "<<endl
#define  deb2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define  deb3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define  deb4(a, b, ser, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#ser<<": "<<ser<<" | "<<#d<<": "<<d<<endl
#define  FF first
#define  SS second
#define  yes "YES"
#define  no "NO"
#define  PI 3.141592653589793238462643383279502884L
#define printv(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" "
// find_by_order(p)  returns iterator to kth element starting from 0;
// order_of_key(p) returns count of elements strictly smaller than p;
//order of key returns the index if the element was present.(If not present)
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll Ceil(ll a, ll b) {return a / b + (a % b != 0);}
ll Logn(ll m, ll r) {return (m > r - 1) ? 1 + Logn(m / r, r) : 0;}
ll fastModExp(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res;}
ll GCD(ll a, ll b) { if (b == 0)return a; else  return GCD(b, a % b);}
//Chrnlgy: Binary Search,Greedy,dp,dfs and similar

ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}


/*
ll xo,yo,z;
void exten_euclid(ll a,ll b)
{   ll temp;
    if(b==0)
    {
        z=a;
        xo=1;
        yo=0;
    }
    else
    {
        exten_euclid(b,a%b);
        temp=xo;
        xo=yo;
        yo=temp-(a/b)*yo;
    }
return;
}



//     O(sqrtn)

vector<ll> factorize(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

*************FACTORIZE IN 0(LOG(N)) PROVIDED N IS INTEGER**************

int minPrime[100000];

void modified_sieve(int n){
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}
}

vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

*************************************************
void sieve(int N) {
        bool isPrime[N+1];
        for(int i = 0; i <= N;++i) {
            isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
    }


ll binomialCoeff(ll n, ll k)    //Time Compx: O(k)// when Using Dp then O(n*k)
{
     ll res = 1;
    if(n<k)
    return 0;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}


bool dfs_cycle(int root){
vis[root]=1;
bool temp=false;
for(int i=0;i<G[root].size();i++)
{
int v=G[root][i];
if(vis[v]==0)
temp|=dfs_cycle(v);
else if(vis[v]==1)
return true;
}
vis[root]=2;
return temp;
}

vector<vector<int> > G;
vector<int> vis;
bool is_cyclic(int n){
    vector<int> mark(2000,-1);
    queue<int> q;
    q.push(n);
    mark[n]=0;
    while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int i=0;G[v].size();i++){
        int nbs=G[v][i];
        if(mark[nbs]==-1){
        q.push(nbs);
        mark[nbs]=0;
        }
        else if(mark[nbs]==0) return true;
    }
    mark[v]=1;
    }
    return false;
}





void DFS_UTIL(ll u){
    vis[u]=true;

    for(auto it=G[u].begin();it!=G[u].end();it++){
        if(vis[*it]==false)
        {
        DFS_UTIL(*it);
        }
    }
}



map<int, int> par, rk;
void make_set(int n) // the rank and parent
{
    for (int i = 1; i <= n; i++) { par[i] = i; rk[i] = 1; }
}

int find( int x)   // with PATH COMPRESSION
{
    if (x == par[x]) return x;
    int p = find(par[x]);
    par[x] = p;
    return p;
}

int uni(int x, int y) // with UNION BY rank
{
    int p1 = find(x);
    int p2 = find(y);
    if (p1 == p2 ) return 0;
    if ( rk[p1] >= rk[p2] ) { par[p2] = p1; rk[p1] += rk[p2]; }
    else { par[p1] = p2; rk[p2] += rk[p1]; }
    return 1;
}
/*


void bfs(int o,int dp[],int n){
    queue<int> q;
    q.push(o);
    dp[o]=0;
    bool visited[n+1]={0};
    visited[o]=true;
    while(q.empty()==false){
        int a=q.front();
        q.pop();
        for (int u : G[a]) {
            if(visited[u]==false){
                visited[u]=true;
                q.push(u);

                dp[u]=dp[a]+1;
            }
        }
    }
}

struct Comp {
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }

};
*/


void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

void rightrotate(string &s, int d)
{
    leftrotate(s, s.length() - d);
}





int main()
{
    FIFO;


    return 0;
}