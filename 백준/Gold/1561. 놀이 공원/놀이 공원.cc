#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;


signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	ll n, m;
	cin >> n >> m;



	vector<ll> t(m+ 1);
	for(ll i = 1; i <= m; i++){
		cin >> t[i];
	}
	if(n <= m){
		cout << n << '\n';
		return 0;
	}
	ll lo = 1; ll hi = 1e18;
	ll ti = 1e18;

	ll tot = 0;
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		
		bool of = 0;
		ll cnt = 0;
		for(int i = 1; i <= m; i++){
			cnt += (mid / t[i] + 1);
			if(cnt < 0) of = 1;
		}

		//cout << "mid cnt: " << mid << ' ' << cnt << '\n';
		if(cnt > n-1 || of){
			hi = mid - 1;
		}
		else if(cnt <= n-1){
			ti = mid;
			tot = cnt;
			lo = mid + 1;
		}
	}

	//cout << ti << ' ' << tot << '\n';

	vector<pair<ll, ll>> v;
	for(int i = 1; i <= m; i++){
		v.push_back({ t[i] - (ti % t[i]) ,i});
	}

	sort(v.begin(), v.end());
	for(auto w : v){
		//cout << w.first << ' ' << w.second << '\n';
	}
	
	ll diff = n - tot;
	//cout << "diff: " << diff << '\n';
	ll ans = v[diff - 1].second;


	//cout << "diff dt: " << diff << ' ' << ans << '\n';
	cout << ans;

}





