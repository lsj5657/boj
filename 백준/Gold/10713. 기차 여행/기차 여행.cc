#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second

int n, m;
int a[100005], b[100005], c[100005];
int pref[100005];
int p[100005];

signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> p[i];
	}

	for(int i = 1; i <= n - 1; i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	for(int i = 1; i < m; i++){
		int cur = p[i]; int nxt = p[i + 1];
		if(cur > nxt) swap(cur, nxt);
		pref[cur]++; pref[nxt]--;
	}

	for(int i = 1; i <= n; i++){
		pref[i] += pref[i - 1];
	}

	int ans = 0;
	for(int i = 1; i < n; i++){
		int c1 = a[i] * pref[i];
		int c2 = c[i] + b[i] * pref[i];
		ans += min(c1, c2);
	}

	cout << ans;

}
