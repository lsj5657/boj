#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, w, ans;
vector<pair<int, int>> adj[300006];


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);


	int tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		w = ans = 0;
		for(int i = 1; i <= n; i++){
			adj[i].clear();
		}
		for(int i = 0; i < n - 1; i++){
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({w,v});
			adj[v].push_back({w,u});
		}
		
		int ans = 0;

		for(int i = 1; i <= n; i++){
			int sum = 0, mx = 0;
			for(auto t : adj[i]){
				int nxt_w, nxt;
				tie(nxt_w, nxt) = t;

				sum += nxt_w;
				mx = max(mx, nxt_w);
			}

			int en = 0;
			sum -= mx;

			if(mx >= sum){
				en = mx - sum;
			}
			else{
				en = (sum+mx) % 2;
			}
			
			//cout << "mx sum: " << mx << ' ' << sum << '\n';
			//cout << "i en: " << i << ' ' << en << '\n';
			ans += en;
		}

		cout <<  ans / 2 << '\n';

	}

}
