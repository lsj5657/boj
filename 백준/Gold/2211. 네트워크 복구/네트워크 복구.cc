#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

int dist[1005];
vector<pair<int,int>>adj[1005];
int pre[1005];


signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({c,v});
		adj[v].push_back({c,u});
	}

	for(int i = 0; i <= n; i++) {
		dist[i] = 1e15;
	}
	dist[1] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({dist[1],1});

	while(!pq.empty()){
		int d, cur;
		tie(d, cur) = pq.top(); pq.pop();
		if(dist[cur] != d) continue;

		for(auto nxt : adj[cur]){
			if(dist[nxt.second] <= dist[cur] + nxt.first) {
				continue;
			}
			pre[nxt.second] = cur;
			dist[nxt.second] = dist[cur] + nxt.first;
			pq.push({dist[nxt.second],nxt.second});
		}

	}


	cout << n - 1 << '\n';
	for(int i = 2; i <= n; i++){
		cout << i << ' ' << pre[i] << '\n';
	}



}
