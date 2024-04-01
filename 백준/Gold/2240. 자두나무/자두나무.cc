#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[1005];
int dp[1005][35][3];


int func(int i, int move, int t){
	if(move > m) return 0;
	if(i == n + 1) return 0;

	

	int& ret = dp[i][move][t];
	
	if(ret != -1) {
		return ret;
	}

	
	ret = 0;
	if(t == a[i]){
		ret = max(ret, 1 + func(i + 1, move, t));
		if(move<m)ret = max(ret, 0 + func(i + 1, move + 1, 3 - t));
	}
	else{
		if(move < m)ret = max(ret, 1 + func(i + 1, move + 1, 3 - t));
		ret = max(ret, 0 + func(i + 1, move, t));
	}

	//cout << "i move t: " << i << ' ' << move << ' ' << t << '\n';
	//cout << "ret:" << ret << '\n';
	return ret;
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	memset(dp, -1, sizeof(dp));
	cout << func(1, 0, 1);

	
}
