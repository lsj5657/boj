#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<tuple<int,int,int>> adj[15];
pair<int,int> v[15];

void dfs(int cur, int par){

	for(auto nxt : adj[cur]){
		if(get<0>(nxt) == par) continue;
		int V, p, q;
		tie(V, p, q) = nxt;
		v[V] = {v[cur].first * p, v[cur].second * q};
		dfs(V, cur);

	}
}

int gcd(int a, int b){
	if(a == 0)return b;
	else return gcd(b % a, a);
}

int lcm(int a, int b){
	return a / gcd(a,b) * b;
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v, p, q;
		cin >> u >> v >> p >> q;
		adj[u].push_back({v,p,q});
		adj[v].push_back({u,q,p});
	}


	v[0] = {1,1};
	dfs(0, -1);

	int l = 1;
	int g = 0;
	for(int i = 0; i < n; i++){
		int tmpg = gcd(v[i].first, v[i].second);
		v[i].first /= tmpg;
		v[i].second /= tmpg;
		g = gcd(g, v[i].second);
	}

	for(int i = 0; i < n; i++){
		v[i].second /= g;
		l = lcm(l, v[i].first);
	}


	g = 0;
	for(int i = 0; i < n; i++){
		v[i].second = v[i].second * l / v[i].first;
		g = gcd(g, v[i].second);
	}

	for(int i = 0; i < n; i++){
		v[i].second /= g;
		cout << v[i].second << ' ';
	}

	


}



