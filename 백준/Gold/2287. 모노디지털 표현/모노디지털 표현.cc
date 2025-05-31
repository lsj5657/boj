#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define int long long

set<int> st[10];
map<int, int> mp;


void func(int d, int x){
	if(mp.count(x))return;
	st[d].insert(x);
	mp[x] = d;
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int k;
	cin >> k;
	st[0].insert(0);
	st[1].insert(k);
	mp[0] = 0;
	mp[k] = 1;

	int q = k;
	for(int i = 2; i <= 8; i++){
		for(int j = 0; j <= i; j++){
			set<int> f = st[j];
			set<int> b = st[i - j];

			for(auto e1 : f){
				for(auto e2 : b){
					int res1 = e1 * e2;
					func(i, res1);
					int res2 = e1 + e2;
					func(i, res2);
					if(e2 != 0) {
						int res3 = e1 / e2;
						func(i, res3);
						/*cout << "i: " << i << '\n';
						cout << "e1 e2: " << e1 << ' ' << e2 << '\n';
						cout << "j kk res1 res2 res3: " << j << ' ' << kk << ' ' << res1 << ' ' << res2 << ' ' << res3 << '\n';*/
					}
					int res4 = e1 - e2;
					if(res4>=0)func(i, res4);



				}

			}
		}

		//cout << "i q: " << i << ' ' << q << '\n';
		q = q * 10 + k;
		func(i, q);


	}

	for(int i = 0; i <= 8; i++){

		/*cout << "i: " << i << '\n';
		for(auto w : st[i]) cout << w << ' ';
		cout << '\n';*/

	}

	int n;
	cin >> n;

	while(n--){
		int a;
		cin >> a;

		if(mp.count(a)) cout << mp[a] << '\n';
		else cout << "NO\n";
		
	}


	

}

