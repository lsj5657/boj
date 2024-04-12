#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<bool> isprime(1000006, true);


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	isprime[1] = 0;
	for(int i = 2; i * i <= n; i++){
		if(!isprime[i]) continue;
		for(int j = i * i; j <= n; j += i){
			isprime[j] = 0;
		}
	}

	vector<int> v;
	for(int i = 1; i <= n; i++){
		if(isprime[i]) v.push_back(i);
	}

	vector<pair<int, int>> num(1000001);

	vector<int> ans;
	if(n % 2){
		ans.push_back(2); ans.push_back(3);
		n -= 5;
	}
	else{
		ans.push_back(2); ans.push_back(2);
		n -= 4;
	}

	for(int i = 2; i <= n-2; i++){
		int l = i; int r = n - i;
		if(isprime[l] && isprime[r]){
			cout << ans[0] << ' ' << ans[1] << ' ' << l << ' ' << r;
			return 0;
		}
	}

	cout << -1;


}