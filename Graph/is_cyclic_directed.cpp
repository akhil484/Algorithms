#include<bits/stdc++.h>
using namespace std;
bool is_cyclic(vector<vector<int> >&adjList, int v, vector<int>&vis) {
    vis[v] = 0;
    bool ans = false;
    for (int i = 0; i < adjList[v].size(); i++) {
        int nbs = adjList[v][i];
        if (vis[nbs] == -1) {
            vis[nbs] = 0;
            ans |= is_cyclic(adjList, nbs, vis);
        }
        else if (vis[nbs] == 0) return true;
    }
    vis[v] = 1;
    return ans;

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
    }
    vector<int> vis(n, -1);
    if (is_cyclic(adjList, 0, vis)) cout << "It is a cyclic graph...." << endl;
    else cout << "Not a cyclic graph...." << endl;
}

