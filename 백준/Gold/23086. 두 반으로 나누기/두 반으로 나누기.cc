#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
vector<int> adj[100006];
pair<int, int> edge[200006];
int c[100006];
bool ok = 1;

void dfs(int cur,int t){

	//cout << "cur c t: " << cur << ' ' << c[cur] << ' ' << t << '\n';
	if(!c[cur]) c[cur] = t;
	else {
		if(c[cur] != t) ok = 0;
		return;
	}

	for(int nxt : adj[cur]){
		dfs(nxt, 3 - t);
	}
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;

	for(int i = 1; i <= m; i++){
		cin >> edge[i].first >> edge[i].second;
	}

	vector<int> fr(k + 1);
	for(int i = 1; i <= k; i++){
		cin >> fr[i];
	}

	int ans = -1;
	int a = 0, b = 0;
	int s = 0; int e = k;
	while(s <= e){
		int mid = (s + e) / 2;
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			c[i] = 0;
		}

		vector<bool> era(m + 1);
		for(int i = 1; i <= mid; i++){
			era[fr[i]] = 1;
		}

		for(int i = 1; i <= m; i++){
			if(era[i]) continue;
			adj[edge[i].first].push_back(edge[i].second);
			adj[edge[i].second].push_back(edge[i].first);
		}


		ok = 1;
		dfs(1, 1);

		int t1 = 0, t2 = 0;
		for(int i = 1; i <= n; i++){
			if(c[i] == 1) t1++;
			else if(c[i] == 2)t2++;
			else ok = 0;
		}

		if(t1 > t2)swap(t1, t2);

		/*cout << "mid: " << mid << '\n';
		for(int i = 1; i <= n; i++){
			cout << c[i] << ' ';
		}
		cout << '\n';*/

		if(ok){
			ans = mid;
			a = t1;
			b = t2;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}

	}

	cout << ans << '\n';
	if(ans == -1) return 0;
	cout << a << ' ' << b;
	

}
