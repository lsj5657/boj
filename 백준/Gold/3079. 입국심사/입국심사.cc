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

	vector<ll> t(n + 1);
	for(ll i = 1; i <= n; i++){
		cin >> t[i];
	}

	ll lo = 1; ll hi = 1e18;
	ll ans = 1e18;
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		//cout << "mid: " << mid << '\n';
		
		bool of = 0;
		ll cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt += mid / t[i];
			if(cnt < 0) of = 1;
		}

		if(cnt >= m || of){
			ans = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}

	cout << ans;

}





