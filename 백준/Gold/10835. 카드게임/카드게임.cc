#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[2005][2005];
int a[2005], b[2005];

int func(int l, int r){
	if(l > n || r > n) return 0;
	int& ret = dp[l][r];
	if(ret != -1) return ret;

	ret = 0;
	ret = max(ret, func(l + 1, r));
	ret = max(ret, func(l + 1, r + 1));
	if(a[l] > b[r]){
		ret = max(ret, b[r]+ func(l, r + 1));
	}

	return ret;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	memset(dp, -1, sizeof(dp));

	cout << func(1, 1);

}



