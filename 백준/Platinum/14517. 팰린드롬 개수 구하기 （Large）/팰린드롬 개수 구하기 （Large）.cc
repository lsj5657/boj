#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 10007;
int dp[1005][1005];
string s;
int n;

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> s;
	n = s.length();
	s = ' ' + s;

	
	for(int len = 1; len <= n; len++){
		if(len == 1){
			for(int i = 1; i <= n; i++) dp[i][i] = 1;
			continue;
		}

		if(len == 2){
			for(int i = 1; i < n; i++){
				if(s[i] == s[i + 1]){
					dp[i][i + 1] = 3;
				}
				else{
					dp[i][i + 1] = 2;
				}
			}
		}
		else{
			for(int i = 1; i <= n; i++){
				int j = i + len - 1;
				if(j > n) break;

				dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] +mod - dp[i + 1][j - 1])%mod;
				if(s[i] == s[j]) dp[i][j] += (dp[i + 1][j - 1] + 1)%mod;

				dp[i][j] %= mod;
			}
		}




	}
	cout << dp[1][n];
	
}
