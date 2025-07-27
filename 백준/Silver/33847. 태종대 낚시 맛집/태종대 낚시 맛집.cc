#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define int long long

int dp[1000006];



signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int n, c;
	cin >> n >> c;
	
	vector<tuple<int, int, int>> v;
	for(int i = 1; i <= n; i++){
		int x, s, w;
		cin >> x >> s >> w;
		v.push_back({x,s,w});
	}

	int ans = 0;

	for(int i = 1; i <= 10000; i++){
		vector<bool> use(n);
		int cnt = 0;
		int t = i;
		int money = 0;

		int cost = 0;
		while(cnt < n){
			int sz = -1;
			int idx = -1;
			int m = -1;

			for(int j = 0; j < n; j++){
				if(use[j]) continue;
				int x, s, w;
				tie(x, s, w) = v[j];
				if(x <= t){
					if(s > sz){
						sz = s;
						idx = j;
					}
				}
			}

			if(idx == -1) break;
			use[idx] = 1;
			money += get<2>(v[idx]);
			t -= get<0>(v[idx]);
			cost += (get<0>(v[idx])) * c;
			ans = max(ans, money - cost);
			cnt++;
		}


	}

	cout << ans;
	



}





