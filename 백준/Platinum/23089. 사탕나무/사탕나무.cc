#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100006][32];
int tmp[100006][32];
int n, k;
vector<int> adj[100006];
int ans;

void dfs(int cur, int par,int d){
	dp[cur][0] = 1;

	for(int nxt : adj[cur]){
		if(nxt == par)continue;
		dfs(nxt, cur, d + 1);
		for(int i = 1; i <= k+3; i++){
			dp[cur][i] += dp[nxt][i - 1];
		}
	}

}

void reroot(int cur, int par){
	int sum = 0;
	for(int i = 0; i <= k; i++){
		sum+= dp[cur][i];
	}

	/*cout << "cur sum: " << cur << ' ' << sum << '\n';
	for(int i = 0; i <= 10; i++){
		cout << dp[cur][i] << ' ';
	}
	cout << '\n';*/
	ans = max(ans, sum);

	for(int nxt : adj[cur]){
		if(nxt == par) continue;
		vector<int> tmp(k + 5);

		for(int i = 0; i <= k + 3; i++){
			tmp[i] = dp[cur][i];
		}
		for(int i = 1; i <= k + 3; i++){
			tmp[i] -= dp[nxt][i - 1];
		}

		for(int i = 1; i <= k + 3; i++){
			dp[nxt][i] += tmp[i - 1];
		}

		reroot(nxt, cur);
	}
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;

	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, -1, 0);

	/*for(int i = 1; i <= n; i++){
		cout << "i: " << i << '\n';
		for(int j = 0; j <= 10; j++){
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/
	reroot(1, -1);

	cout << ans;
}
