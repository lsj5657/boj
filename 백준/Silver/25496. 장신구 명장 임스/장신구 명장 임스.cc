#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second

int p, n;


signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> p >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a.begin() + 1, a.end());

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(p >= 200) break;
		ans++;
		p += a[i];
	}

	cout << ans;
}
