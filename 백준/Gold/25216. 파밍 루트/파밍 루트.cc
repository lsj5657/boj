#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, T;
int a[5005], x[5005], y[5005], c[5005];
vector<int>adj[5005];
int dp[5005][105];
int mx;

int dfs(int cur, int t,int def){
	if(t == T) return 0;

	int& ret = dp[cur][t];
	if(ret != -1) return ret;

	ret = 0;
	int dmg = max(0ll, a[cur] + x[cur] * t - y[cur] * def);
	if(dmg)return 0;

	for(int nxt : adj[cur]){
		ret = max(ret, dfs(nxt, t + 1,def));
	}

	ret += c[cur];

	return ret;
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> T;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> x[i] >> y[i] >> c[i];
	}
	
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	memset(dp, -1, sizeof(dp));
	int s = 0; int e = 1e14;
	mx = dfs(1, 0, e);

	int ans = e;
	while(s <= e){
		int mid = (s + e) / 2;

		memset(dp, -1, sizeof(dp));
		if(mx == dfs(1, 0, mid)){
			e = mid - 1;
			ans = mid;
		}
		else{
			s = mid + 1;
		}
	}

	cout << ans;
}
