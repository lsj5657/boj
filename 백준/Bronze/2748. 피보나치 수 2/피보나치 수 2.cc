#include <bits/stdc++.h>
using namespace std;
#define ll long long


int n;
ll dp[95];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
	
}

