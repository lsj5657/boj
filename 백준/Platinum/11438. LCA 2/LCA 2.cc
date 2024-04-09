#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[100006];
int p[100006][33];
int depth[100006];

void dfs(int cur, int par){
	p[cur][0] = par;
	for(int i = 1; i <= 32; i++){
		p[cur][i] = p[p[cur][i - 1]][i - 1];
	}

	for(int nxt : adj[cur]){
		if(nxt == par) continue;
		depth[nxt] = depth[cur] + 1;
		dfs(nxt, cur);
	}
}

int lca(int u, int v){
	if(u == 1 || v == 1) return 1;

	if(depth[u] > depth[v]) swap(u, v);

	if(depth[u] != depth[v]){
		for(int i = 32; i >= 0; i--){
			if(!p[v][i]) continue;
			if(depth[u] <= depth[p[v][i]]) v = p[v][i];
		}
	}
	
	int ret = u;
	if(u != v){
		for(int i = 32; i >= 0; i--){
			if(!p[v][i]) continue;
			
			if(p[u][i] != p[v][i]){
				u = p[u][i]; v = p[v][i];
			}
			else ret = p[u][i];
		}
	}
	return ret;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	int m;
	cin >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

}
