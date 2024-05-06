#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int s[1005];
int dp[1005][1005];
int a, d;

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];

	cin >> a >> d;


	for(int i = n; i >= 1; i--){
		dp[i][0] = s[i] + dp[i + 1][0];
		for(int j = 1; j <= n; j++){
			int nxt = i + d;
			if(nxt > n){
				dp[i][j] = a;
			}
			else{
				dp[i][j] = dp[nxt][j - 1] + a;
			}

			dp[i][j] = max(dp[i][j], dp[i + 1][j] + s[i]);
		}
	}

	int ans = -1;
	for(int i = 0; i <= n; i++){
		//cout << "i dp: " << i << ' ' << dp[1][i] << '\n';
		if(dp[1][i] >= m){
			ans = i;
			break;
		}
	}

	cout << ans;
}