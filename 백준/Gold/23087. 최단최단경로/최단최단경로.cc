#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 9;
int n, m;
int dist[100006];
int cnt[100006];
int path[100006];
int x, y;
vector<pair<int,int>> adj[100006];

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> x >> y;
	for(int i = 0; i <= n; i++){
		dist[i] = cnt[i] = 1e18;
	}
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w,v});
	}

	priority_queue<tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>> pq;
	dist[x] = 0;
	cnt[x] = 0;
	path[x] = 1;
	pq.push({dist[x],0,x});

	while(!pq.empty()){
		int d, c, cur;
		tie(d, c, cur) = pq.top(); pq.pop();
		//cout << "cur: " << cur << '\n';
		if(dist[cur] != d) continue;

		for(auto nxt : adj[cur]){
			if(dist[nxt.second] < dist[cur] + nxt.first) {
				continue;
			}
			else if(dist[nxt.second] == dist[cur] + nxt.first){
				if(c+1 < cnt[nxt.second]){
					cnt[nxt.second] = c + 1;
					path[nxt.second] = path[cur];
				}
				else if (c+1==cnt[nxt.second]){
					path[nxt.second] += path[cur];
				}
				path[nxt.second] %= mod;
				continue;

			}
			else{
				cnt[nxt.second] = c + 1;
				dist[nxt.second] = dist[cur] + nxt.first;
				path[nxt.second] = path[cur];
				pq.push({dist[nxt.second],c + 1,nxt.second});
			}
		}
	}

	if(dist[y] == 1e18){
		cout << -1;
		return 0;
	}
	cout << dist[y] << '\n' << cnt[y] << '\n' << path[y];

}
