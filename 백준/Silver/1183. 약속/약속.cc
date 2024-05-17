#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second


int a[55], b[55];

signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	int mn = 1e18;
	int mx = -1e18;
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		v.push_back(b[i] - a[i]);
	}

	if(n % 2) cout << 1;
	else{
		sort(v.begin(), v.end());
		int idx = (v.size() - 1) / 2;

		cout << v[idx + 1] - v[idx] + 1;
	}
	

}
