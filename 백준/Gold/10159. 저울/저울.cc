#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
set<int> st[105];
vector<int> adj[105];
bool vis[105];

void dfs(int s,int cur){
	vis[cur] = 1;
	for(auto nxt : adj[cur]){
		if(vis[nxt]) continue;
		st[s].insert(nxt);
		st[nxt].insert(s);
		dfs(s,nxt);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;


	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) vis[j] = 0;
		dfs(i,i);
	}

	for(int i = 1; i <= n; i++){
		cout << n - st[i].size()-1 << '\n';
	}
	
	

}



