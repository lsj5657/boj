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

	int n;
	cin >> n;
	vector<ll> x(n);
	for(int i = 0; i < n; i++) cin >> x[i];

	/*for(int k = 1; k <= 20; k++){
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += abs(x[i] - k * i);
		}
	}*/


	ll ans;
	ll lo = 1; ll hi = 1e18;
	while(lo <= hi){
		ll mid = (lo + hi) / 2;

		ll sum1 = 0, sum2 = 0;

		bool of = 0;
		for(int i = 0; i < n; i++){
			sum1 += abs(x[i] - mid * i);
			sum2 += abs(x[i] - (mid+1) * i);
			if(sum1 < 0 || sum2 < 0) of = 1;
		}

		if(of){
			hi = mid - 1;
		}

		if(sum1 <= sum2){
			ans = sum1;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	cout << ans;


}





