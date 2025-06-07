#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;

int n, m, k;
int dp[1005][1005];
vector<pair<int, int>> adj[1005];

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> k;


	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = 1e9;
		}
	}

	int src, dst;
	cin >> src >> dst;

	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({w,b});
		adj[b].push_back({w,a});
	}



	dp[src][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	pq.push({0,0, src});

	while(!pq.empty()){
		int d, cnt, cur;
		tie(d, cnt, cur) = pq.top(); pq.pop();
		//cout << "d c cur: " << d << ' ' << c << ' ' << cur << '\n';

		if(dp[cur][cnt] < d) continue;



		for(auto w : adj[cur]){
			int cost, nxt;
			tie(cost, nxt) = w;

			int new_cost = d + cost;
			int new_cnt = cnt + 1;

			if(new_cnt > n) continue;

			if(dp[nxt][new_cnt] > new_cost){
				dp[nxt][new_cnt] = new_cost;
				pq.push({new_cost,new_cnt,nxt});
			}

			
			
		}
	}

	/*for(int i = 1; i<=n; i++){
		cout << dp[dst][i] << ' ';
	}
	cout << '\n';*/

	
	int duty = 0;
	for (int i=0;i <=k; i++){
		int p; 
		if(i == 0) p = 0;
		else cin >> p;
		duty += p;

		int ans = 1e9;
		for(int i = 1; i <= n; i++){
			ans = min(ans, dp[dst][i] + duty * i);
		}

		cout << ans << '\n';
	}




}





