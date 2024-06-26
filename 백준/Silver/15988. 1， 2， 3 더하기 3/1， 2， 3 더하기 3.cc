#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int MAX = 1000000;
ll mod = 1e9 + 9;
ll dp[1000006];


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i = 4; i <= MAX; i++){
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
	}

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

}


